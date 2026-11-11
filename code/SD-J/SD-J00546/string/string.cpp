#include<bits/stdc++.h>
using namespace std;
long long n,a,ans;char x;string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>x;
		for(int j=1;j<=a;j++){
			s+=x; 
		}
	}
	int l=0,r=s.size()-1;
	while(l<=r){
		if(s[l]!=s[r]) ans++;
		l++;r--;
	}
	cout<<ans;
	return 0;
}
