#include<bits/stdc++.h>
using namespace std;
char a,b[100100],c[100100];
int n,s,h=0,k=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s>>a;
        if(s<=50)
        {
            for(int j=h+1;j<=h+s;j++)
            b[j]=a;
            h=h+s;
        }
    }
    if(h%2==0)
    {
        for(int i=h/2+1;i<=h;i++)
        c[i]=b[h+1-i];
        for(int i=1;i<=h/2;i++)
        c[i]=b[i];
        for(int j=1;j<=h;j++)
        {
            if(c[j]!=b[j])
            k++;
        }
        cout<<k;
    }
    if(h%2!=0)
    {
        for(int i=(h+1)/2+1;i<=h;i++)
        c[i]=b[h+1-i];
        for(int i=1;i<=(h+1)/2;i++)
        c[i]=b[i];
        for(int j=1;j<=h;j++)
        {
            if(c[j]!=b[j])
            k++;
        }
        cout<<k;
    }
    return 0;
}

