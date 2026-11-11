#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		for(int j=1;j<=x;j++){
			s+=y;
		}
	}
	int len=s.size();
	for(int i=0;i*2<len;i++){
		if(s[i]==s[len-i-1]){
			continue;
		}
		else{
			ans++;
		}
	}
	cout<<ans;
	 
	return 0;
}
