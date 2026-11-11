#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll maxn=2e5+50;

ll n;
ll f[maxn];
char ch[maxn];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>f[i]>>ch[i];
	}
	
	ll ans=0;
	int l=1,r=n;
	while(l<r){
		if(ch[l]!=ch[r]){
			ans+=min(f[l],f[r]);
		}
		if(f[l]>f[r]){
			f[l]=f[l]-f[r];
		    r--;
		}
		else if(f[l]<f[r]){
			f[r]=f[r]-f[l];
			l++;
		}
		else{
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
