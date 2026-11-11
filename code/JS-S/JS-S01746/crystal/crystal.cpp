#include<bits/stdc++.h>
using namespace std;
long long n,m,k,maxn=INT_MIN,minn=INT_MAX,ans,f1=1,f2=1,y,z,cha;
map<long long,long long> mp;
struct node{
    long long val,cnt;
}a[500001];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        long long x;cin>>x;
        mp[x]++;
        maxn=max(maxn,x),minn=min(minn,x);
        if(i==1) y=x;
        else if(i==2) cha=x-y,z=x;
        else{
            if(x-z!=cha) f2=0;
            z=x;
        }
        if(x!=i) f1=0;
    }
    if(f1==1){
        long long sum1=0;
        bool t1=0;
        for(long long i=1;i<n;i++){
            sum1+=i;
            if(sum1>m){
                sum1=i;
                t1=1;
                break;
            }
        }
        if(t1==1) cout<<sum1;
        else cout<<n;
    }
    else if(f2==1){
        long long sum2=y;
        bool t2=0;
        for(long long i=1;i<n;i++){
            sum2=sum2+i*cha;
            if(sum2>m){
                sum2=i;
                t2=1;
            }
        }
        if(t2==1) cout<<sum2;
        else cout<<n;
    }
    else{
        for(long long i=minn;i<=maxn;i++){
            if(mp[i]!=0) a[++k].val=i,a[k].cnt=mp[i];
        }
        for(long long i=1;i<=k;i++){
            long long sum=a[i].cnt,u=0;
            for(long long j=i-1;j>=1;j--){
                u=u+(a[i].val-a[j].val)*a[j].cnt;
                if(u>m){
                    long long t=u-m,v=a[i].val-a[j].val;
                    if(t%v==0) sum=sum+a[j].cnt-(t/v);
                    else sum=sum+a[j].cnt-(t/v+1);
                    break;
                }
                else sum+=a[j].cnt;
            }
            ans=max(ans,sum);
        }
        cout<<ans;
    }

    return 0;
}
