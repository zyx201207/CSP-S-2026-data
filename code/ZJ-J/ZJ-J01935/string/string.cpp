#include<bits/stdc++.h>
using namespace std;
long long n,cnt,m,ans;
char s[10000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long lin;
	long long num;
	char a;
	long long x=0;
	for(int i=1;i<=n;i++){
		cin>>num>>a;
		for(int j=1;j<=num;j++){
			s[x+j]=a;
		}
		x+=num;
	}
	for(int i=1;i<=x/2;i++){
		if(s[i]!=s[x-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}