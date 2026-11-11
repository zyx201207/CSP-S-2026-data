#include<bits/stdc++.h>
using namespace std;
string q;
int a,n,sum,ans;
char c,s[10000000]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			sum++;
			s[sum]=c;				
		}
	}
	for(int i=1;i<=ceil(double(sum)/2);i++){		
		if(s[i]!=s[sum-i+1]) ans++;
	}
	cout<<ans;
	return 0;
}
