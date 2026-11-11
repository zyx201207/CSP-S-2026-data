#include<bits/stdc++.h>
using namespace std;
#define _ long long
_ a,b,c,ans;
vector<_>v[35];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b;
	for(_ i=1;i<=a;i++){
		cin>>c;
		v[31].push_back(c);
	}
	for(_ i=31;i;i--){
		for(_ j:v[i]){
			if((j>>(i-1))&1)v[i-1].push_back(j);
		}
		if(v[i-1].size()>=b){
			ans+=(1<<(i-1));
			continue;
		}
		for(_ j:v[i]){
			if(!((j>>(i-1))&1))v[i-1].push_back(j);
		}
	}
	cout<<ans;
	return 0;
}