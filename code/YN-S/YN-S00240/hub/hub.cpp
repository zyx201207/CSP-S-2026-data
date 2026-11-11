#include<iostream>
#include<cstdio>
#include<chrono>
#include<ctime>
#include<random>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rint(int l,int r){
	return uniform_int_distribution<int>(l,r)(rng);
}


int c,t;
int n,k;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1,u,v;i<n;i++)
			cin>>u>>v;
		cout<<rint(1,n)<<"\n";
	}
	return 0;
}
