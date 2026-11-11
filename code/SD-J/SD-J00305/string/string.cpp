#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int num;
	char c;
}a[200200],b;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0,ans=0;
	string s="";
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
		for(int j=1;j<=a[i].num;j++){
			s+=a[i].c;
		}
	}
	for(int i=0;i<s.length()/2;i++){
		if(s[i]!=s[s.length()-1-i]) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
