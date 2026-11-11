#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long ans=0;
	int n;
	cin>>n;
	string s;
	long long l=0;
	for(int i=1;i<=n;i++){
		long long x;
		l+=x;
		char c;
		cin>>x;
		cin>>c;
		for(int i=1;i<=x;i++){
			s+=c;
		}
	}
	for(int L=0,R=l-1;L<=R;L++,R--){
		if(s[L]!=s[R]) ans++;
	}
	cout<<ans;
	return 0; 
} 

