#include<bits/stdc++.h>
#include<vector>
using namespace std;
typedef long long ll;
ll n,m;ll s;
ll a[200200];
vector<ll>f[33];
vector<ll>v;
ll pw[33]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<=30;j++)if(a[i]&pw[j])f[j].push_back(i);
	}
	int pi=30;
	while(f[pi].size()<m&&pi>=0)pi--;
	s=pw[pi];
	v=f[pi];
	for(int i=1;i<=30;i++)f[i].clear();
	for(int i=0;i<v.size();i++){
		for(int j=0;j<=30;j++)if(a[v[i]]&pw[j])f[j].push_back(v[i]);
	}
	for(int h=pi-1;h>=0;h--){
		if(f[h].size()<m)continue;
		s+=pw[h];
		if(v.size()<=m)continue;
		v=f[h];
		for(int i=0;i<=30;i++)f[i].clear();
		for(int i=0;i<v.size();i++){
			for(int j=0;j<=30;j++)if(a[v[i]]&pw[j])f[j].push_back(v[i]);
		}
	}
	cout<<s<<"\n";
}
