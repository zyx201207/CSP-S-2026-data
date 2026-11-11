#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
char c[200005];
int l=1;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	c[1]='0';
	for(int i=1;i<=n;i++){
		char cc;
		int x;
		cin>>x>>cc;
		if(cc==c[l-1]){
			a[l-1]+=x;
		}
		else{
			c[l]=cc;
			a[l]=x;
			l++;
		}
	}
	l--;
	int i=1,j=l,ans=0;
	while(i<j){
		int mi=min(a[i],a[j]);
		if(c[i]!=c[j]){
			ans+=mi;
		}
		a[i]-=mi,a[j]-=mi;
		if(a[i]==0)i++;
		if(a[j]==0)j--;
//		cout<<ans<<'\n';
	}
	cout<<ans;
	return 0;
}
