#include<bits/stdc++.h>
using namespace std;
vector<char> v;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,ans=0;
	cin>>n;
	for(int i = 1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		for(int j = 1;j<=x;j++){
			v.push_back(y);
		}
	}
	
	long long l=v.size()-1;
	
	for(int i = 0;i<(l+1)/2;i++){ 
		if(v[i]!=v[l-i]){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
