#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[200005];
char c[200005];
ll L,L2,k[200005],te,ans=0;
vector<ll> v;
vector<char> v1,v2;
void zh(){
	ll now=0;
	int l=0,r=n;
	while(l<r){
		int t=min(k[l+1]-now,L-k[r-1]-now);
		if(k[l+1]-now<L-k[r-1]-now){
			v.push_back(k[l+1]-now);
			v1.push_back(c[l+1]);
			v2.push_back(c[r]);
			l++;
		}
		else if(k[l+1]-now>L-k[r-1]-now){
			v.push_back(L-k[r-1]-now);
			v1.push_back(c[l+1]);
			v2.push_back(c[r]);
			r--;
		}
		else{
			v.push_back(L-k[r-1]-now);
			v1.push_back(c[l+1]);
			v2.push_back(c[r]);
			l++;
			r--;
		}
		now+=t;
		te++;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		L+=a[i];
		k[i]=k[i-1]+a[i];
	}
	L2=L/2.0+0.5;
	zh();
	for(int i=0;i<te;i++){
//		cout<<v1[i]<<" "<<v2[i]<<"\n";
		if(v1[i]!=v2[i]) ans+=v[i];
	}
	cout<<ans;
	return 0;
}