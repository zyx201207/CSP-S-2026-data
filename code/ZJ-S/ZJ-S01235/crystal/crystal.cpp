#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m,a[N],b[N],l,ans;
bool flag=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(i>=2&&a[i]-a[i-1]!=a[2]-a[1]) flag=false;
	}
	if(flag){
		int d=a[2]-a[1];
		for(int i=1;i<=n;i++){
			if((i-1)*d*i/2>m){
				cout<<i-1;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		l=0;
		long long h=m;
		for(int j=i;j>=1;j--){
			if(a[i]-a[j]<=h){
				h-=a[i]-a[j];
				l++;
			}
			else break;
		}
		ans=max(ans,l);
	}
	cout<<ans;
	return 0;
}