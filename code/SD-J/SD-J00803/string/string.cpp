#include<iostream>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;
const int N=2e5+7;
int n,a[N],ans;
char c[N]; 
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		int x=min(a[l],a[r]);
		if(c[l]!=c[r]) ans+=x;
		a[l]-=x;
		a[r]-=x;
		if(!a[l]) l++;
		if(!a[r]) r--;
	}
	cout<<ans;
	return 0;
}
