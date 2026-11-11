#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,a[500010],b[500010];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<n;i++){
		b[i] = a[i+1]-a[i];
	}
	for(int i = 1;i<n;i++){
		b[i]+=b[i-1];
	}
	int ans = 0;
	for(int i = 1;i<n;i++){
		if(b[i]>m){
			break;
		}
		ans++;
	}
	cout<<ans+1;
	return 0;
}