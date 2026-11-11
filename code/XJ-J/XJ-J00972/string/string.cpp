#include<bits/stdc++.h>
using namespace std;
int n,a,flag=0;
char c,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	for(int i=0;i<s.size()-1;i++){
		if(s[i]==s[i+1]) flag=1;
		else flag=0;
		ans=s[i]|s[i+1];
		//cout<<ans<<endl;
	}
	if(n==1||flag==1){
		cout<<0;
	}
	else if(n==2) cout<<2;
	else if(int(ans-'a')<=s.size()) cout<<int(ans-'a');
	else cout<<s.size()-1;
	return 0;
}
