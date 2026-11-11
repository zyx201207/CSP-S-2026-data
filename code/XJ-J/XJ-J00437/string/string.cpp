#include <bits/stdc++.h>
using namespace std ;
const int N=2e5+5;
int ans=0,n,num;
char v;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num>>v;
		for(int j=1;j<=num;j++)
			s+=v;
	}
	int len=s.size();
	if(len%2==0){
		for(int i=0;i<=(len-1)/2;i++){
			if(s[i]!=s[len-i-1]) ans++;
		}
		
	}else{//一会要检查这里len0~/2
		for(int i=0;i<=(len-1)/2;i++){
			if(s[i]!=s[len-i-1]) ans++;
		}
	}
	cout<<ans;
		return 0;
}