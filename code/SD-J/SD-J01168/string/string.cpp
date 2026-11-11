#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Q{
	int a;
	string b;
}q[10001];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++){
		cin>>q[i].a>>q[i].b;
		for(int j=1;j<=q[i].a;j++){
			s+=q[i].b;
		}
	}
	int ans=0;
	for(int i=0,j=s.size()-1;i<=j;i++,j--){
		if(s[i]!=s[j]){
			s[j]=s[i];
			ans++;
		}
		if(i==j){
			break;
		}
	}
	cout<<ans;
	return 0;
}
