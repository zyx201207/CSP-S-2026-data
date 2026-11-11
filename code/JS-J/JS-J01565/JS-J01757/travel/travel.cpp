#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("travel.in", " r" stdin)
    //freopen("travel.out", " w" stdout)
    int fark;
    int k=1;
    int l1,l2;
    cin>>l1;
    string a,b;
    cin>>a;
    cin>>l2;
    cin>>b;
    int x[3],y[3];
    char z[3];
    for(int i=0;i<=2;i++)
    {
        if(i==0)
            x[k]=a[0];
        if(i==1)
            y[k]=a[1];
        if(i==2)
            z[k]=a[2];
    }
    k+=1;
    for(int i=0;i<=2;i++)
    {
        if(i==0)
        {
            x[k]=b[0];
        }
        if(i==1)
        {
            y[k]=b[1];
        }
        if(i==2)
        {
            z[k]=b[2];
        }
    }
    int daan[5];
    if(l1==l2)
    {
        daan[1]=1;
    }
    else{
        daan[1]=0;
    }

    if(x[1]*10+y[1]==x[2]*10+y[2] && l1==l2)
    {
        daan[2]=1;
    }
    else{
        daan[2]=0;
    }

    if(((z[1]=='A'&&z[2]=='B')||(z[1]=='B'&&z[2]=='A')||(z[1]=='A'&&z[2]=='C')||(z[1]=='C'&&z[2]=='A')||(z[1]=='B'&&z[2]=='C')||(z[1]=='C'&&z[2]=='B')||(z[1]=='D'&&z[2]=='F')||(z[1]=='F'&&z[2]=='D'))&&l1==l2&&x[1]*10+y[1]==x[2]*10+y[2])
    
    {
        daan[3]=1;
    }
    else{
        daan[3]=0;
    }

    if(((z[1]=='A'&&z[2]=='B')||(z[1]=='B'&&z[2]=='A')||(z[1]=='B'&&z[2]=='C')||(z[1]=='C'&&z[2]=='B')||(z[1]=='D'&&z[2]=='F')||(z[1]=='F'&&z[2]=='D'))&&l1==l2&&x[1]*10+y[1]==x[2]*10+y[2])
    {
        daan[4]=1;
    }
    else{
        daan[4]=0;
    }
    for(int i=1;i<=4;i++)
    {
        cout<<daan[i];
    }
    return 0;
}