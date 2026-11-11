#include<bits/stdc++.h>
using namespace std;
long long n,ans=0,a[200005]={0},b[200005]={0},cnt=0,p=0,o=0;
string s;
int main(){freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	cin>>n;	
	for(int i=1;i<=n;i++){
		long long a;
		string b;
		cin>>a>>b;
		ans+=a; 
		for(int j=1;j<=a;j++)s=s+b;
	}
	if(ans%2==1){
		for(int i=ans/2-1;i>=0;i--){
			a[p]=s[i];
			p++;
		}
		for(int i=ans/2+1;i<=ans-1;i++){
			b[o]=s[i];
			o++;
		}
		for(int i=0;i<=o;i++){
			if(a[i]!=b[i])cnt++;
		}
	}
	else{
		if(s[ans/2-1]!=s[ans/2])cnt++;
		for(int i=ans/2-2;i>=0;i--){
			a[p]=s[i];
			p++;
		}
		for(int i=ans/2+1;i<=ans-1;i++){
			b[o]=s[i];
			o++;
		}
		for(int i=0;i<=o;i++){
			if(a[i]!=b[i])cnt++;
		}
	}cout<<cnt;
	return 0;
}

