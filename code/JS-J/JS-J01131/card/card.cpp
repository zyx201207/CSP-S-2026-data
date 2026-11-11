#include<bits/stdc++.h>
using namespace std;
unsigned long long num[200005],n=0,tot=0,cnum=0,midnum=0,delta=0,le=0,ri=0,lel=0,ril=0;
char nc[200005],lec,ric;
char mid()
{
    long long m=0;
    int i=1;
    while(m+num[i]<midnum)
    {
        m+=num[i];
        i++;
    }
    return nc[i];
}
char judgechar(long long nu)
{
     long long m=0;
    int i=1;
    while(m+num[i]<nu)
    {
        m+=num[i];
        i++;
    }
    return nc[i];

}
long long judgela(long long nu)
{
    long long m=0;
    int i=1;
    while(m+num[i]<nu)
    {
        m+=num[i];
        i++;
    }
    return nu-m;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%lld",&n);

    char midal;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&num[i]);
        scanf("%s",&nc[i]);
        tot+=num[i];
    }
    if(tot%2==0)
    {
        midnum=tot/2;//midnum is on the left.
        midal=mid();//the middle character
        le=midnum;//the left point and the right point
        ri=midnum+1;
        lec=judgechar(le);
        lel=judgela(le);
        if(ric!=midal)
            ril=judgela(ri);
        else
            ril=judgela(ri)-midnum;
         while(le>0||ri<=tot)
        {
            if(ric!=lec)//while character unequal
            {
                if(ril>lel)
                {

                    cnum+=lel;
                    ril-=lel;
                    ri+=lel;
                    le-=lel;
                    lec=judgechar(le);
                    lel=judgela(le);
                }
                else   if(ril<lel)
                {
                    cnum+=ril;
                    lel-=ril;
                    ri+=ril;
                    le-=ril;
                    ric=judgechar(ri);
                    ril=judgela(ri);
                }
                else{
                    cnum+=lel;
                    ril-=lel;
                    ri+=lel;
                    le-=lel;
                    lec=judgechar(le);
                    lel=judgela(le);
                    ric=judgechar(ri);
                    ril=judgela(ri);
                }
            }
            else//while character equal
            {
                if(ril>lel)
                {
                    ril-=lel;
                    ri+=lel;
                    le-=lel;
                    lec=judgechar(le);
                    lel=judgela(le);
                }
                else if(ril<lel)
                {
                    lel-=ril;
                    ri+=ril;
                    le-=ril;
                    ric=judgechar(ri);
                    ril=judgela(ri);
                }
                else
                {
                    lel-=ril;
                    ri+=ril;
                    le-=ril;
                    ric=judgechar(ri);
                    ril=judgela(ri);
                    lec=judgechar(le);
                    lel=judgela(le);
                }
            }
        }
    }
    else
    {
        midnum=(tot+1)/2;
        midal=mid();
        le=midnum-1;//the left point and the right point
        ri=midnum+1;
        lec=judgechar(le);
        lel=judgela(le);
        ric=judgechar(ri);
        if(ric!=midal)
            ril=judgela(ri);
        else
            ril=judgela(ri)-midnum;
        while(le>0&&ri<=tot)
        {
            if(ric!=lec)//while character unequal
            {
                if(ril>lel)
                {
                    cnum+=lel;
                    ril-=lel;
                    ri+=lel;
                    le-=lel;
                    lec=judgechar(le);
                    lel=judgela(le);
                }
                else   if(ril<lel)
                {
                    cnum+=ril;
                    lel-=ril;
                    ri+=ril;
                    le-=ril;
                    ric=judgechar(ri);
                    ril=judgela(ri);
                }
                else{
                    cnum+=lel;
                    ril-=lel;
                    ri+=lel;
                    le-=lel;
                    lec=judgechar(le);
                    lel=judgela(le);
                    ric=judgechar(ri);
                    ril=judgela(ri);
                }
            }
            else//while character equal
            {
                if(ril>lel)
                {
                    ril-=lel;
                    ri+=lel;
                    le-=lel;
                    lec=judgechar(le);
                    lel=judgela(le);
                }
                else if(ril<lel)
                {
                    lel-=ril;
                    ri+=ril;
                    le-=ril;
                    ric=judgechar(ri);
                    ril=judgela(ri);
                }
                else
                {
                    lel-=ril;
                    ri+=ril;
                    le-=ril;
                    ric=judgechar(ri);
                    ril=judgela(ri);
                    lec=judgechar(le);
                    lel=judgela(le);
                }
            }
        }
    }
    printf("%lld",cnum);
    return  0;
}
