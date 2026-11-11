#include<bits/stdc++.h>
using namespace std;
long long x[3000000];
vector<int>ma[3000000];
void dji(){
	//R.I.P
	//feile
	//qing
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	long long c,t;
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++)
		    for(int j=i+1;j<=n;j++) if(abs(x[i]-x[j])<=d) ma[i].push_back(j),ma[j].push_back(i);
		dji();
	}
	return 0;
}