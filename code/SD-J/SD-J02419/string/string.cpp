#include<bits/stdc++.h>
using namespace std;
#define int long long  
const int N=2e5+10;
int n,a[N],ans;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r){
		if(c[l]!=c[r]){
			ans+=min(a[l],a[r]);
		}
		if(a[l]>a[r]){
			a[l]-=a[r];
			r--;
		}
		else if(a[l]==a[r]){
			l++;
			r--;
		}
		else{
			a[r]-=a[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
}

