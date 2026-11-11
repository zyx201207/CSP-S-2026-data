#include <bits/stdc++.h>
using namespace std;
long long n,a,ans=0,x,i,j;
char c;
string s;
int main(){
	freopen("string.in ","r",stdin);
	freopen("string.out ","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
	
		cin>>a>>c;
		for(j=1;j<=a;j++){
			s+=c;
			x++;
		}
		
	 

	}
	for(i=0;i<=x/2;i++){
		if(s[i]!=s[x-i-1]){
			ans++;
		}
	}
	cout<<ans;
return 0;
}