check=input()
check=check.split(" ")
time=int(check[1])
ques=int(check[0])
count=0
for i in range(0,time):

    a=input()
    b=input()
    a=a.split(" ")
    b=b.split(" ")
    c=list()
    num=int(a[0])
    flymax=int(a[1])

    for i in range(0, num):
        c.append(int(b[i]))
    c.sort()

    # c list   flymax  num

    d = list()
    for i in range(0, num - 1):
        d.append(int(c[i + 1]) - int(c[i]))

    for i in range(0,num-2):
        choice_able=0
        flag=0
        while(d[i+flag]<=flymax):


            if (flag+i+1<=num-2 and d[i+flag]+d[i+flag+1]<flymax+1):

                if(flag+2+i<=num-2 and d[i+flag+1]+d[i+flag+2]<flymax+1):

                    choice_able=1
                    break
            if (flag+i==num-2):
                choice_able=-1
                break

            flag+=1
        if (choice_able==1):
            count+=1
            choice_able=0
        elif (choice_able==-1):
            choice_able=0
    print(count)
    count=0
