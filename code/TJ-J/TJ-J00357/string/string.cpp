#include <bits/stdc++.h>
using namespace std;
long long n,cnt=0;string k,k2;
int main(){
	string a;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int u;char r;
		cin>>u>>r;
		for(int j=1;j<=u;j++){
			k+=r;
			k2+=r;
		}
	}reverse(k2.begin(),k2.end());
	for(int i=0;i<=n/2;i++){
		if(k[i]!=k2[i])cnt++;
	}cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
