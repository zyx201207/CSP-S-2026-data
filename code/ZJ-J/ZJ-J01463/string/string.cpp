#include<bits/stdc++.h>
using namespace std;
string s;
long long k=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a;
	for(int i=1;i<=n;i++){
		cin>>a;
		char c;
		cin>>c;
		for(int j=1;j<=a;j++){
			s[k]=c;
			k++;
		}
	}
	long long ans=0;
	for(int i=1;i<(k/2);i++){
		if(s[i]!=s[k-i-1]){
			ans++;
		}
	}
	cout<<ans;
}
