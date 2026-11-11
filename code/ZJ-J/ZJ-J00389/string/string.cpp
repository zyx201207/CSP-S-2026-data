#include<bits/stdc++.h>
using namespace std;
long long n,ans;
char c;
string st;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int x,i=1;i<=n;i++){
		cin>>x>>c;
		for(int j=1;j<=x;j++) st+=c;
	}
	for(int i=0;i<st.size()/2;i++)
		if(st[i]!=st[st.size()-i-1]) ans++;
	cout<<ans;
}
//RP++
