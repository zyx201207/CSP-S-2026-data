#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
	}
int main(){
//	  _________
//	 |         |
//	 |  R.I.P. |
//	 |         |
//	 |   ***   |
//	 |   2026  |
//	 |         |
//	 |         |
//=================
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a,b;
	int s[200010];
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	sort(s+1,s+n+1,cmp);
	int ans=s[1]&s[2];
	cout<<ans;
	return 0;
}
