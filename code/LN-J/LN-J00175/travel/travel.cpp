#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	string a,az,b,bz;
	cin>>a>>az>>b>>bz;
	if(a.size()!=b.size()){
		cout<<"0000"<<'\n'; 
		return;
	}
	int sum=a.size();
	for(int i=0;i<sum;i++){
		if(a[i]!=b[i]){
			cout<<"0000"<<'\n';
			return;
		}
	}
	for(int i=0;i<sum;i++){
		if(az[i]!=bz[i]){
			cout<<"1000"<<'\n';
			return;
		}
	}
	if(az[az.size()-1]<='C' && bz[bz.size()-1]>='D'){
		cout<<"1100"<<'\n';
		return;
	}
	if(az[az.size()-1]>='D' && bz[bz.size()-1]<='C'){
		cout<<"1100"<<'\n';
		return;
	}
	if(az[az.size()-1]=='C' && bz[bz.size()-1]=='D'){
		cout<<"1110"<<'\n';
		return;
	}
	if(az[az.size()-1]=='D' && bz[bz.size()-1]=='C'){
		cout<<"1110"<<'\n';
		return;
	}
	if(az[az.size()-1]+1!=bz[bz.size()-1] && az[az.size()-1]-1!=bz[bz.size()-1]){
		cout<<"1110"<<'\n';
		return;
	}
	cout<<"1111"<<'\n';
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	solve();
    return 0;
}
