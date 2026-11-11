#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,ans=0;
	long long l=0,cnt=0;
	string c;
	cin>>n;s='0';
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
		l+=a;
	}
	
	for(int i=1;i<=l/2;i++){
		if(s[i]!=s[l-i+1]){
			cnt++;
		}
			
	}
	cout<<cnt;
	return 0;
}
