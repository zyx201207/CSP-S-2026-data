#include<iostream>
#include<vector>
#include<random>
using namespace std;
#define int long long
int c;
void sol(){
	int n,k;
	cin>>n>>k;
	for(int i=0,u,v;i<n;i++)
		cin>>u>>v;
	cout<<k/2<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
	int t;
	for(cin>>t;t--;sol());
}
