from random import randint

n=randint(1,1000)
m=randint(3,500)

with open("card.in","w") as f:
    f.write(f"{n} {m}\n")
    for _ in range(n):
        f.write(f"{randint(1,m+1)} ")