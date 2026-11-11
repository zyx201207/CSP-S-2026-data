#include<bits/stdc++.h>
using namespace std;
int n,a,ans, c=1;
char s[2000005];
char b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int len = 1;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=c;j<=c+a-1;j++){
			s[j] = b;
			len++;
		}
		c+=a;
	}
	
	for(int i=1;i<=len/2;i++){
		if(s[i] != s[len-i+1]){
			ans++;
		}
	}
	
	cout<<ans;
	return 0;
}