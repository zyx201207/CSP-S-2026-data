#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=5e5+10;
int a[N];
map<int,int> mp;
int p[N],ans[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cout.tie(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        mp.clear();
        for(int j=i;j<=n;j++){
            if(mp.find(a[j])!=mp.end()&&mp[a[j]]){
                int l=mp[a[j]];
                for(int k=l;k<=j;k++)p[k]=0,mp[a[k]]=0;
                p[j]=a[j];
                mp[a[j]]=j;
            }
            else{mp[a[j]]=j;p[j]=a[j];}
        }
        for(int j=1;j<=n;j++){ans[p[j]]++;p[j]=0;}
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    return 0;
}
