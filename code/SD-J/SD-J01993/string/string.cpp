#include <bits/stdc++.h>
using namespace std;
const long long MAX=1000000005;
long long ans,r;
char s[MAX];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char b;
		cin>>a>>b;
		for(int j=r;j<r+a;j++){
			s[j]=b;
		}
		r+=a;
	}
	for(int i=0,j=r-1;i<=j;i++,j--){
		if(s[i]!=s[j]) ans++;
	}
	cout<<ans; 
	return 0;
}
