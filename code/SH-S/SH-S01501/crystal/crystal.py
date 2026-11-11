
a=input()
b=input()
a=a.split(" ",1)
b=b.split(" ")
c=list()
num=int(a[0])
countmax=int(a[1])

for i in range(0,num):
    c.append(int(b[i]))
c.sort()

d=list()
for i in range(0,num-1):
    d.append(int(c[i+1])-int(c[i]))

count = 0
times=0
oldtimes=0
for i in range(0,num-1):
    flags = 1
    while(count<=countmax):
        if (i+flags<num):

            count += flags * d[i+flags-1]
        else:
            break
        flags+=1
        times+=1

    if(times>oldtimes):
        oldtimes=times
    times=0

print(oldtimes)


