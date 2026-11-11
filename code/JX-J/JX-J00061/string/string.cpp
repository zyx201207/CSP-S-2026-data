#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s="";
	long long n1=0,ans=0;
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		n1+=a;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	int l=0,r=n1-1;
	while(l<=r){
		if(s[l]!=s[r]){
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;
}
