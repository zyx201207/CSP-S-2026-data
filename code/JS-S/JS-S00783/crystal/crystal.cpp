#include<bits/stdc++.h>
using namespace std;

int n,ans=1;
long long m;
long long a[500005],s[500005];
bool check(int x,int now){
    long long sum=a[now]*(long long)(now-x)-(s[now-1]-s[x-1]);
    if(sum<=m){
        //cout<<x<<' '<<now<<' '<<sum<<endl;
        ans=max(ans,now-x+1);
        return true;
    }
    return false;
}
void Search(int Left,int Right){
    int l=Left-1,r=Right+1,mid;
    while(l+1<r){
        mid=(l+r)/2;
        if(check(mid,Right+1)){
            r=mid;
        }
        else l=mid;
    }
    return ;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
       scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        Search(1,i-1);
    }
    cout<<ans<<endl;
    return 0;
}
