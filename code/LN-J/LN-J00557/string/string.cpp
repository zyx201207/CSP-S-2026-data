#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
string s="";
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	int l=s.size();
	if(l%2==0){
		for(int i=0;i<=l/2-1;i++){
			if(s[i]!=s[l-1-i]) ans++;
		}
	}else{
		for(int i=0;i<l/2;i++){
			if(s[i]!=s[l-1-i]) ans++;
		}
	}
	cout<<ans;
	return 0;
}
