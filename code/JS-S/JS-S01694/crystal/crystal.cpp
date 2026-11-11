#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define tiao cout<<"Rikki_official"<<'/n'
const ll N=5e5+100,M=1e18+100;
ll n,m,mm,cntm,zhizhen,s,ans=0;
ll a[N],b[N];
inline int find_num(int j){
    int x=1,cnt=0;
    for(int i=j-1;i>=1;i--){
        if(cnt+a[j]-a[i]<=m){
            x+=1;
            cnt=cnt+a[j]-a[i];
        }else{
            break;
        }
    }
    return x;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    mm=a[1];
    for(int i=2;i<=n;i++){
        cin>>a[i];
        if(a[i]>mm){
            mm=a[i];
            cntm=0;
        }
        if(a[i]==mm){
            cntm+=1;
        }
    }
    sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            b[i]=mm-a[i];
        }
        for(int i=2;i<=n;i++){
            int x=find_num(i);
            if(x>ans)ans=x;
        }
    cout<<ans<<'\n';
    return 0;
}
