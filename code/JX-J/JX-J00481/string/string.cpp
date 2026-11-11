#include<bits/stdc++.h>
using namespace std;
int str(string a11,string b11){
	string s1=a11,s2=b11;
	int ans=0,m=a11.size()/2;
	for(int i=0;i<m;i++){
		if(s1[i]!=s2[i]){
			++ans;
		}
	}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,x;cin>>n;
	string a[n+1],b,b1;
	for(int i=1;i<=n;i++){
		cin>>x>>a[i];
		while(x--){
			b+=a[i];
			b1=a[i]+b1;
		}
	}
	cout<<str(b,b1);
	return 0;
}


