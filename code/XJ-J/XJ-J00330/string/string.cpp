#include<bits/stdc++.h>
using namespace std;
const long long int N=2e5+10;
long long int n,a[N],x,ans;
char c[N];
string s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		while(a[i]--){
			s[++x]=c[i];
		}
	}
	for(int i=1;i<=x/2;i++){
		if(s[i]!=s[x+1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}