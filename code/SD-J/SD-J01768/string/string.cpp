#include<bits/stdc++.h>
using namespace std;
char s[10000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,n,k=0;
	char b;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=k;j<=a+k;j++){
			s[j]=b;
		}
			k+=a;
		

	}
	long long ans=0;

		int x=0,y=k-1;
		while(y>x){
			if(s[x]!=s[y]) ans++;
			x++,y--;
		}
	cout<<ans;
	
}
