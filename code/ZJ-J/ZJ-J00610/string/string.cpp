#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	int ans=0;
	int l=0,r=s.size()-1;
	while(l<=r){
		if(s[l]!=s[r]){
			ans++;
			l++;
			r--;
		}
		else{
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
