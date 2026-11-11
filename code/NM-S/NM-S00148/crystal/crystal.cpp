#include<bits/stdc++.h>
using namespace std;
long long n,mm,a[500010];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>mm;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    long long ans=1,maxx=-1,m=mm;
    for(int i=1;i<=n;i++){
        m=mm;
        ans=1;
        for(int j=i+1;j<=n;j++){
            if(a[i]-a[j]<=m){
                m-=(a[i]-a[j]);
                ans++;
            }
            else{
                break;
            }
        }
        maxx=max(maxx,ans);
    }
    cout<<maxx;
    return 0;
}
