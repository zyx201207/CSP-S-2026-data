#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
struct node{
	ll x;
	char c;
}a[200010];
ll len,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		for(int j=1;j<=a[i].x;j++) s=s+a[i].c;
	}
	len=s.size();
	for(int i=0;i<len;i++){
		if(2*i>len) break;
		if(s[i]!=s[len-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
/*
int rp=0;
while(1) rp++;
*/
