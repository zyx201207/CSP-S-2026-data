#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int flag=0;
	for(int i=1;i<=n;i++){
		b[i]=a[i+1]-a[i];
		if(b[i]<=m){
//			if(flag==1&&b[i]+b[i-1]<=m){
//				a[i-1]+=b[i];
//			}
			a[i]+=b[i];
			m-=b[i];
			flag=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i+1]-a[i]<=m){
			a[i]+=a[i+1]-a[i];
		}
	}
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
