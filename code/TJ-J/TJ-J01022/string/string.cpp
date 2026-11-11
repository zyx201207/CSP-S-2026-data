#include<bits/stdc++.h>
using namespace std;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	string s = "";
	for(int i=0;i<n;i++){
		int k,l;
		cin>>k>>l;
		for(int j=0;j<k;j++){
			s.push_back(l);
		}
	}
	
	int p = 0; int q = n-1;
	int ans =0;
	while(p<q){
		if(s[p]!=s[q]) ans++;
		p++;q++;
	}
	
	cout<<ans<<'\n';
	
	return 0;
}
