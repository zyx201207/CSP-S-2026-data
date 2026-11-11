#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(false);
	cout.tie(0);
	int n;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		for(int i=1;i<=x;i++){
			s+=y;
		}
	}
	int l=0;
	int r=s.size()-1;
	int ans=0;
	while(l<r){
		if(s[l]!=s[r]){
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;
}
