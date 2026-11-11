#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int a[N],b[N],ans;
ll n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int ch=a[2]-a[1];
	bool f=1;
	for(int i=2;i<=n;i++){
		if(ch!=(a[i]-a[i-1]))
			f=0;
	}
	if(f==1){
		int x=0;
		while((1+x)*x*ch*1.0/2<=m) x++;
		x--;
		cout<<x+1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int j=i-1;
		ll tm=m;
		int sum=0;
		while(a[i]-a[j]<=tm && j>=1 && tm>0){
			tm-=(a[i]-a[j]);
			j--;
			sum++;
		}
		ans=max(ans,sum);
	}
	cout<<ans+1;
	return 0;
}