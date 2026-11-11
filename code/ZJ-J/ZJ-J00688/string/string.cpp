//Trick||Treat!
#include <bits/stdc++.h>
using namespace std;
char c[100000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a;
	char temp;
	long long l=0,j=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>temp;
		l+=a;
		for(j=j;j<=l;j++){
			c[j]+=temp;
		}
	}
	int ans=0;
	for(int i=1;i*2<=l;i++){
		//cout<<i<<" "<<c[i]<<" "<<c[l-i+1]<<endl;
		//si = sL+1-i
		if(c[i]!=c[l-i+1]){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
