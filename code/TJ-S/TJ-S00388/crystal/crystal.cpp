#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	vector<long long>v;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		v.push_back(k);
	}
	for(int i=n;i>=0;i--){
		int ans=0;
		for(int j=0;j<i;j++){
			ans+=(v[i]-v[j]);
		}
		if(ans==m){cout<<i+1; return 0;}
	}
}
//Oct31==Dec25?
//5 8
//-3 -1 2 2 7
