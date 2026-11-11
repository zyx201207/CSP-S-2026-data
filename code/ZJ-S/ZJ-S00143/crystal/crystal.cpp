#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],s[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		s[i]=s[i-1]+a[i]-a[i-1];
	}
	s[0]=0;
	s[1]=0;
	for(int i=1,j=1;j<=n&&i<=j;j++){
		if(s[j]-s[i-1]<=m){
			ans=max(ans,j-i+1);
		}
		else{
			while(s[j]-s[i-1]>m) i++;
			ans=max(ans,j-i+1);
		}
	}
	cout<<ans;
	return 0; 
}
//Oct31==Dec25?