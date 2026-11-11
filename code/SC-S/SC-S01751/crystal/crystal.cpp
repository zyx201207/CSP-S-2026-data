#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAX=5e5+5;
int n,m,a[MAX],ans=1;
bool f1=true,f2=true;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)f1=false;
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2])f2=false;
	}
	sort(a+1,a+1+n);
	if(n==1){
		cout<<"1\n";
		return;
	}else if(f1){
		int i,sum=0;
		for(i=1;sum<=m&&i<=n;i++)sum+=i;
		cout<<i-1<<'\n';
		return;
	}
	if(f2){
		int i,sum=0;
		for(i=1;sum<=(m/(a[2]-a[1]))&&i<=n;i++)sum+=i;
		cout<<i-1<<'\n';
		return;
	}
	for(int i=1;i<=n;i++){
		int res=0;
		for(int j=i-1;j>=1&&res+a[i]-a[j]<=m;j--){
			res+=(a[i]-a[j]);
			ans=max(ans,i-j+1);
		}
	}
	cout<<ans<<'\n';
}
#undef int
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T=1;
//  cin>>T;
	while(T--)solve();
	return 0;
}