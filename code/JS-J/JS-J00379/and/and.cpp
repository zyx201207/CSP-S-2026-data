#include<bits/stdc++.h>
using namespace std;
const int maxn=2*1e5+5;
long long n,m,a[maxn],ans;
void dfs(int pos,int step,long long sum){
    if(step==m){
        ans=max(ans,sum);
        return;
    }
    for(int i=pos+1;i<=n-m+step+1;i++) dfs(i,step+1,sum&a[i]);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n>2000){
        int cnt=2147483647;
        sort(a+1,a+n+1);
        for(int i=n;i>=n-m+1;i--) cnt=cnt&a[i];
        cout<<cnt;
        return 0;
    }
    for(int i=1;i<=n-m+1;i++) dfs(i,1,a[i]);
    cout<<ans;
	return 0;
}
/*
I often recall about the past.
*/
