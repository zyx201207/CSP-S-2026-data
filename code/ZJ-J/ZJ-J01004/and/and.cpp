#include<bits/stdc++.h>
#define int long long
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
vector<int> v,v1;
int s,ans,a,n,m;
void f(int d){
	int t[40]={0},l,r=-1;
	l=v.size();
	for(int i=0;i<l;i++){
		int c=0;
		int k=v[i];
		while(k){
			if(k%2==1) t[c]++;
			c++,k/=2;
		}
	}
	for(int j=d;j>=0;j--){
		if(t[j]>=m){
			r=j;
			break;
		}
	}
	if(r==-1) return;
	s=1;
	for(int j=1;j<=r;j++) s*=2;
	ans+=s;
	v1.clear();
	for(int i=0;i<l;i++)
		if(v[i]>=s) v1.push_back(v[i]-s);
	v.clear();
	l=v1.size();
	for(int i=0;i<l;i++) v.push_back(v1[i]);
	f(r-1); 
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	FIO
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		v.push_back(a);
	}
	f(31);
	cout<<ans;
	return 0;
}