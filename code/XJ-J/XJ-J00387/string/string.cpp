#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//const int N=;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	string s;
	cin>>n;
	int len=0;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
			len++;
		}
	} 
//	cout<<s<<"\n";
	int l=0,r=s.size()-1;
	int ans=0;
	while(l<=r){
		if(s[l]!=s[r]){
			ans++;
		}
		l++,r--;
	}
	cout<<ans;
	return 0;
}


