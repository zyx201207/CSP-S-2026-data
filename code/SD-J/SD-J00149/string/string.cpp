#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,a[N],ans;
char c[N];
string s="";
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r){
		int num=min(a[l],a[r]);
		if(c[l]!=c[r]) ans+=num;
		a[l]-=num,a[r]-=num;
		if(!a[l]) l++;
		if(!a[r]) r--;
	}
	cout<<ans;
	return 0;
} 
