#include<bits/stdc++.h>
using namespace std;
long long read(){
    long long k=0;
    int f=1,c=getchar();
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c)){k=k*10+(c^48);c=getchar();}
    return k*f;
}
int n,m;
long long a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+n+1);
    long long cost=0;
    long long maxa=-1e18-5;
    queue<long long>q;
    long long ans=-1;
    for(int i=1;i<=n;i++){
        if(q.empty()){
            cost=0;
            q.push(a[i]);
            maxa=a[i];
        }else{
            q.push(a[i]);
            long long dif=a[i]-maxa;
            maxa=a[i];
            cost+=((long long)q.size()-1)*dif;
            while(cost>m){
                long long x=q.front();
                q.pop();
                cost-=maxa-x;
            }
        }
        ans=max(ans,(long long)q.size());
    }
    cout<<ans<<endl;
    return 0;
}
