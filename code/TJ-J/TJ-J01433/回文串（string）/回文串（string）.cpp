#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("回文串（string）.in","r",stdin);
	freopen("回文串（string）.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	int n;
	long long ans=0,tot=0;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		string c;
		cin>>a;
		cin>>c;
		for(int j=1;j<=a;j++){
			s+=c;
			tot++;
		}
		
	}
	for(int i=0;i<=tot/2;i++){
		if(s[i]!=s[tot-i-1]){
			ans++;
		}
		
	}
	cout<<ans;
	return 0;
}

