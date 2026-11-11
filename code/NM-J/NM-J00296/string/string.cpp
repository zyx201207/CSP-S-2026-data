#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long cnt=0,sum=0;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	for(int l=0,r=s.size()-1;l<r;l++,r--){
		if(s[l]!=s[r])cnt++;
	} 
	cout<<cnt;
	return 0;
}
