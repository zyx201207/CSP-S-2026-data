#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,r;
ll a[200005],ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	r=n;
	for(int i=1;i<=n;i++){
		while(a[r]<=a[i]&&i!=r){
			if(c[i]!=c[r]) ans+=a[r];
			a[i]-=a[r];
			r--;
		}
		if(c[i]!=c[r]) ans+=a[i];
		a[r]-=a[i];
		if(i==r) break;
	}
	cout<<ans<<"\n";
	return 0;
} 
