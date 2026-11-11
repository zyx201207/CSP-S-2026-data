#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n;
struct nood{
	int nu;
	string s1;
};
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	bool f=0;
	string t;
	vector<nood> a(n+5);
	int q;string s;
	cin>>q>>s;
	a[1].nu=q;
	a[1].s1=s;
	t=s;
	for(int i=2;i<=n;i++){
		cin>>q>>s;
		a[i].nu=q;
		a[i].s1=s;
		if(t!=s)f=1;
		else t=s;
	}
	if(!f){cout<<0;return 0;}
	int l=1,r=n;
	int sum=0,ans=0;
	while(l<=r){
		if(a[l].s1!=a[r].s1){
			int sum1=0;
			ans+=min(a[l].nu,a[r].nu);
			sum+=abs(a[l].nu-a[r].nu);
		}	
		else {
			sum=abs(abs(a[l].nu-a[r].nu)-sum);
			ans+=sum;
		}
		l++;r--;
	}
	cout<<ans;
	return 0;
}
