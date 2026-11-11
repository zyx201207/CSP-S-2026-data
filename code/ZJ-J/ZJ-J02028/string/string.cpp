#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,ans=0,l=0;
	cin>>n;
	string s="";	
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
	}	
	if(n==1){
		cout<<"0";
		return 0;
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	long long le=0,ri=0;
	for(int i=1;i<=l/2;i++){
		if(s[i-1]!=s[l-i]){
			le+=1;
		}
	}
	cout<<le;
	return 0;
}