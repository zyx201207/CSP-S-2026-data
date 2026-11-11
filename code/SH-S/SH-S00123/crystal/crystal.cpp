#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e6+10;
int n,m,a[N],f[N],s[N];
bool ok(int x){
	int req=0;
	for(int i=1;i<=x;i++){
		req+=abs(a[x]-a[i]);
	}
	return (req<=m);
}
void solveA(){
	cout<<n;
}
void solveB(){
	int id=a[2]-a[1];
	int ans=0;
	while(m>=id){
		m-=id;
		ans++;
	}
	cout<<ans;
}
bool cmp(const int &a,const int &b){
	return a>b;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool A=1,B=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1]){
			A=0;
			break;
		}
	}
	for(int i=2;i<n;i++){
		if(a[i-1]-a[i]!=a[i]-a[i+1]){
			B=0;
			break;
		}
	}
	if(A){
		solveA();
		return 0;
	}else if(B){
		solveB();
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++){
		f[i-1]=abs(a[i]-a[i-1]);
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+f[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int sum=0;
		int anst=1;
		for(int j=i+1;j<=n;j++){
			sum+=(s[j]-s[i]);
			if(sum>m)break;
			anst++;
		}
		ans=max(anst,ans);
	}
	cout<<ans;
	return 0;
}
