#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
long long a[N];
int n;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	string s;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++)
		s+=c[i];
	}
	for(int i=1;i<=n;i++){
		if(s[i]==s[n+1-i]){
			cout<<0<<endl;
			return 0;
		}		
	}
	return 0;
}
