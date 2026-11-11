#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		string a;
		cin>>a;
		for(int i=1;i<=x;i++){
			s+=a;
		}
	}
	int h=s.size();
	int len=h/2;
	int u=h-1;
	int ans=0;
	for(int i=0;i<len;i++){
		if(s[i]!=s[u]) ans++;
		u--;
	}
	cout<<ans;
	return 0;
}
