#include <bits/stdc++.h>
using namespace std;
long long n,m[2000005],ans=0,a,num=1;
string x[2000005];
char b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i]>>b;
		a+=m[i];
		for(int j=1;j<=m[i];j++){
			x[num]=b;
			num++;
		}
	}	
	for(int i=1;i<=a/2;i++){
		if(x[i]!=x[a+1-i]){			
			ans++;
		}
	}
	cout<<ans;
	
	
	return 0;
}
