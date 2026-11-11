#include<bits/stdc++.h>
using namespace std;
const int maxn=5*1e5+5;
int n,m,a[maxn],ans=-1e9;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int f=1;
    for(int i=1;i<n;i++) if(a[i+1]-a[i]!=a[2]-a[1]) f=0;
    if(f==1){
        int t=a[2]-a[1],sum=0,cnt=1;
        for(int i=t;sum+i<=m;i+=t) sum+=i,cnt++;
        cout<<cnt;
        return 0;
    }
    for(int i=1;i<=n;i++){
		int sum=0,j=i-1,cnt=1;
		while(sum+abs(a[j]-a[i])<=m&&j>=1) sum+=abs(a[j]-a[i]),j--,cnt++;
		ans=max(ans,cnt);
	}
	cout<<ans;
    return 0;
}
