#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef long long ll;
ll a[N],n,m,ans=0;
vector<ll> bao;
ll b[N];
void sol1(int i){
     if(i>n)return;
     if(bao.size()==m){
        ll res=bao[0];
        for(int i=1;i<bao.size();i++){
            res=res&bao[i];
        }
        ans=max(ans,res);
        return;
     }
     bao.push_back(a[i+1]);
     sol1(i+1);
     bao.pop_back();
     sol1(i+1);
}
void qufan(int i){
     ll res=0,t=a[i];
     while(t>0){
           res=res*10+(!(t%2));
           t/=2;
     }
     b[i]=res;
}
bool cmp(int u,int v){
     return u>v;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=20){
       sol1(0);
       cout<<ans<<endl;
       return 0;
    }
    if(m==1){
       for(int i=1;i<=n;i++){
           ans=max(ans,a[i]);
       }
       cout<<ans<<endl;
       return 0;
    }
    if(m==n){
       ans=a[1];
       for(int i=2;i<=n;i++){
           ans=ans&a[i];
       }
       cout<<ans<<endl;
       return 0;
    }
    if(m==2){
       for(int i=1;i<=n;i++){
           for(int j=i+1;j<=n;j++){
               ans=max(ans,a[i]&a[j]);
           }
       }
       cout<<ans<<endl;
       return 0;
    }
    if(m==n-1){
       int sum=a[1];
       for(int i=2;i<=n;i++){
           sum=sum&a[i];
       }
       for(int i=1;i<=n;i++){
           qufan(i);
           ans=max(ans,sum^b[i]);
       }
       cout<<ans<<endl;
       return 0;
    }
    sort(a+1,a+n+1,cmp);
    ans=a[1];
    for(int i=2;i<=m;i++){
        ans=ans&a[i];
    }
    cout<<ans<<endl;
    return 0;
}
