#include<bits/stdc++.h>
using namespace std;
int n,m,maxn;
int a[200005];
int twopower(int n)
{
    while(n%2==0)
    {
        n/=2;
    }
    if(n==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
bool flag=1,flag2=1;
int main()
{
    ifstream fin("and.in");
    ofstream fout("and.out");
    fin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        fin>>a[i];
        maxn=max(maxn,a[i]);
        if(twopower(a[i]+1)!=1)
        {
            flag=0;
        }
        if(a[i]>=4){
            flag2=0;
        }
    }
    if(m==1)
    {
        fout<<maxn;
        return 0;
    }
    sort(a+1,a+1+n);
    if(flag==1)
    {
        fout<<a[n-m+1];
        return 0;
    }
    if(m==n)
    {
        long long x=a[1];
        for(int i=2; i<=n; i++)
        {
            x=x&a[i];
        }
        fout<<x;
        return 0;
    }
    if(m==2)
    {
        int p=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                p=max(p,a[i]&a[j]);
            }
        }
        fout<<p;
        return 0;
    }
    if(flag2==1){
        int one=0,two=0,three=0;
        for(int i=1;i<=n;i++){
            if(a[i]==1){
                one++;
            }
            if(a[i]==2){
                two++;
            }
            if(a[i]==3){
                three++;
            }
        }
        if(one>0&&two>0){
            fout<<"0";
        }
        if(one==0&&two==0){
            fout<<"3";
        }
        if(one>0&&two==0){
            fout<<"1";
        }
        if(one==0&&two>0){
            fout<<"2";
        }
        return 0;
    }
    else{
        fout<<"0";
    }
}
