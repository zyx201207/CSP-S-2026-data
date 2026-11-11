#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],ans[300005],l[300005],dx[500005];
bool A(){
    for(int i=1;i<n;i++)
        if(a[i]>a[i+1]) return 0;
    return 1;
}
bool B(){
    int cnt=0;
    for(int i=1;i<n;i++)
        if(a[i]!=a[i+1]) cnt++;
    return cnt<=4999;
}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        l[a[i]]=i;
    }
    if(n<=5000){
        for(int i=1;i<=n;i++){
            //cout<<i<<" ";
            int d=i-1;
            while(d<n){
                d++;
                d=l[a[d]];
                //cout<<d<<" ";
                ans[a[d]]++;
            }
            //cout<<"\n";
        }
        for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    }else if(m==2){
        if(a[n]==1){
            int cnt=0;
            for(int i=1;i<=n;i++) cnt+=(a[i]==2);
            cout<<n<<" "<<cnt;
        }else{
            int cnt=0;
            for(int i=1;i<=n;i++) cnt+=(a[i]==1);
            cout<<n<<" "<<cnt;
        }
    }else if(A()){
        for(int i=1;i<=n;i++) ans[a[i]]=i;
        for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    }else{
        /*vector<int>v;
        for(int i=1;i<=n;i++){
            if(a[i]!=a[i-1]) v.push_back(a[i]);
            dx[i]=v.size()-1;
        }
        for(int i=0;i<v.size();i++) l[v[i]]=i;
        for(int i=1;i<=n;i++){
            //cout<<i<<" ";
            int d=dx[i]-1;
            while(d<v.size()){
                d++;
                d=l[a[d]];
                //cout<<d<<" ";
                ans[a[d]]++;
            }
            //cout<<"\n";
        }
        for(int i=1;i<=m;i++) cout<<ans[i]<<" ";*/
        for(int i=1;i<=n;i++){
            //cout<<i<<" ";
            int d=i-1;
            while(d<n){
                d++;
                d=l[a[d]];
                //cout<<d<<" ";
                ans[a[d]]++;
            }
            //cout<<"\n";
        }
        for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    }
    return 0;
}
