#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0;
	string k="";
	cin>>n;
	for(int i=1;i<=n;i++){
		long long g;
		string s;
		cin>>g>>s;
		for(long long j=1;j<=g;j++){
			k+=s;
		}
	}
	int b=k.size()-1;
	for(int i=0;i<b/2;i++){
		if(k[i]!=k[b-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
