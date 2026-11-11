#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,ans;
string s;
struct node{
	int cnt;
	char c;
}a[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	//code
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>a[i].cnt>>a[i].c;
		for(int j=1;j<=a[i].cnt;j++){
			s+=a[i].c;
		}
	}
	ll len=1LL*s.size();
	for(int i=0;i<(len+1)/2;i++){
		ll revi=len-i-1;
		if(s[i]!=s[revi]) ans++;
	}
	cout<<ans;
	return 0;
}
//70 pts
