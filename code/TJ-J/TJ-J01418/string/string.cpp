#include<bits/stdc++.h>
using namespace std;
int n;
string s,st;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char a;
		cin>>x>>a;
		for(int j=1;j<=x;j++){
			s+=a;
			st=a+st;
		}
	}int len=s.size()-1,ans=0;
	for(int i=0;i<=len/2;i++){
		if(s[i]!=st[i]){
			st[i]=s[i];
			s[len-i+1]=st[i];
			ans++;
		}
	}cout<<ans;
	return 0;
}

