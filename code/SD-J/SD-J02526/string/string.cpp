#include<bits/stdc++.h>
using namespace std;
long long n,x,len,ans;
string s,y;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	s[0]=0;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		while(x--){
			s+=y;
		}
	}
	len=s.size()/2;
	for(int i=1;i<=len;i++){
		if(s[i]!=s[len-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
