#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],p[N],s[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	sort(s+1,s+1+n);
	for(int i=1;i<n;i++){
		a[i]=abs(s[i+1]-s[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		int x=abs(s[i+1]-s[i]);
		p[i]=i*x;
		p[i]+=p[i-1];
	}
	for(int i=0;i<=n;i++){
		if(m<p[i]){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<n;
	//for(int i=1;i<=n;i++) cout<<p[i]<<' ';
	return 0;
}