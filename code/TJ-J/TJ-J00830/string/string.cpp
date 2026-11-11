#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s=" ";
	long long si=0;
	for(int i=1;i<=n;i++){
		int m;char c;
		cin>>m>>c;
		si+=m;
		for(int i=1;i<=m;i++){
			s+=c;
		}
	}
	long long l=1,r=si,ans=0;
	while(l<=r){
		if(s[l]!=s[r]) ans++;
		l++;r--;
	}
	cout<<ans;
	return 0;
}
