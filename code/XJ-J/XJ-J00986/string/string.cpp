#include<bits/stdc++.h>
using namespace std;
int n,a,l,cnt;
string s,ans="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>s;
		l+=a;
		for(int j=1;j<=a;j++){
			ans+=s;
		}
	}
	for(int i=0;i<=l/2-1;i++){
		if(ans[i]!=ans[l-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
