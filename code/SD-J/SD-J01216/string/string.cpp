#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
#define endl '\n'
#define ll long long

signed main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n; cin>>n;
	
	string s;	
	
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		
		for(int j=1;j<=a;j++)
			s=s+c;
	}
	
	int ans=0;
	int L=0,R=s.size()-1;
	
	while(L<R){
		if(s[L]!=s[R])
			ans=ans+1;
		L++,R--;
	} 
	cout<<ans;
	
	return 0;
}
