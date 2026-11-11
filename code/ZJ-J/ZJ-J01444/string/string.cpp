#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
string s;
int hs(string t){
	string t1="";
	for(int i=t.size()-1;i>=0;i--) t1=t1+t[i];
	if(t1==t) return 0;
	int cnt=0;
	for(int i=0;i<t.size();i++){
		if(t[i]!=t1[i]) t[i]=t1[i],cnt++;
	}
	return cnt/2;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		char c;
		cin>>c;
		for(int j=1;j<=x;j++){
			s=s+c;
		}
	}
	cout<<(hs(s));
	return 0;
}