#include<bits/stdc++.h>
using namespace std;
long long Read(){
    long long x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-'){
            f=-1;
        }
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-48;
        c=getchar();
    }
    return f*x;
}
long long n,k;
long long a[500005],cha[500005]={},sum[500005]={};
int main(){
    freopen("crystal3.in","r",stdin);
    freopen("crystal3.out","w",stdout);
    n=Read();
    k=Read();
    for(int i=1;i<=n;i++){
        a[i]=Read();
        cha[i]=a[i]-a[i-1];
        sum[i]=sum[i-1]+cha[i];
        //cout<<cha[i]<<' ';
    }
    queue<long long> q;
    long long mx=0,Now=0,l=1,mx2=0,mx2i=0;
    for(int r=1;r<=n;r++){
        if(mx2<a[r]){
            mx2=a[r];
            mx2i=r;
        }
        Now+=(max(max(r-mx2i,mx2i-l),0ll)*cha[r]);
        q.push(r);
        while(Now>k&&q.size()){
            q.pop();
            Now-=(sum[r]-sum[l-1]);
            l++;
        }
        long long siz=q.size();
        mx=max(mx,r-l+1);
        //cout<<Now<<' '<<l<<' '<<r<<' '<<siz<<' '<<mx2i<<'\n';
    }
    cout<<mx;
    return 0;
}
