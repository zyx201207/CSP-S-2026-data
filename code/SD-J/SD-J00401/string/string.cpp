#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,len=0,ans=0;
	string s[1005];	
	cin>>n;

	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		for(int j=1;j<=x;j++){
			s[len]=c;
			len++;
		}
	}
	
	//cout<<s<<" "<<len<<endl;
	
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1]){
			//cout<<s[i]<<" "<<s[len-i-1]<<endl;
			ans++;
		}
	}
	
	cout<<ans;
	return 0;
}
