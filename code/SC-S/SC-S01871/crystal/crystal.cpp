#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
long long m,s[N],a[N];
int n,ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,greater<int>()); 
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int j=2;
	for(int i=1;i<=n;i++){
		while(a[i]*(j-i+1)-(s[j]-s[i-1])<=m&&j<=n) j++;
		j--;
		ans=max(ans,j-i+1);
		if(j==n) break;
	}
	cout<<ans;
    return 0;
} 