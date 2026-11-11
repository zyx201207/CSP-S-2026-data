#include <bits/stdc++.h>
using namespace std;
int ans,a;
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	string v="";
	while(a--){
		int b;
		char c;
		cin>>b>>c;
		for(int i=1;i<=b;i++){
			v+=c;
		}
	}
	for(int i=0;i<=v.size()-1;i++){
		if(v[i]!=v[v.size()-i-1]){
			ans++;
		}
	}
	cout<<ans/2;
	return 0;
}

