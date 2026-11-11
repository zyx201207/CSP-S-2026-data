#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],n,m,ans;
bool ok(int n){
	int x=__builtin_popcount(n);
	int s=1;
	while(x--){
		s*=2;
	}
	return (s==n+1);
}
bool cmp(int x,int y){
	return x>y;
}
bool comp(int x,int y){
	return __builtin_popcount(x)>__builtin_popcount(y);
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int mx=INT_MIN,ans;
	bool can=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		if(!ok(a[i])) can=0;
		if(i==1) ans=a[i];
		else ans&=a[i];
	}
	if(m==1){
		cout<<mx;
		return 0;
	}
	if(can){
		sort(a+1,a+n+1,cmp);
		ans=a[1];
		for(int i=2;i<=m;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		cout<<ans;
		return 0;
	}
	if(m==2&&n<=2000){
		mx=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,(a[i]&a[j]));
			}
		}
		cout<<mx;
		return 0;
	}
	if(n<=10){
		ans=INT_MIN;
		int sum;
		sort(a+1,a+n+1);
		do{
			sum=a[1];
			for(int i=2;i<=m;i++){
				sum&=a[i];
			}
			ans=max(ans,sum);
		}while(next_permutation(a+1,a+n+1));
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1,comp);
	ans=a[1];
	for(int i=2;i<=m;i++){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
