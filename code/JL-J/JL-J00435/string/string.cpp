#include<bits/stdc++.h>
using namespace std;
const int N=1e9+5;
typedef long long LL;
int n,a;
LL p,ans;
char c,s[N];
int main(){
        freopen("string.in","r",stdin);
        freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(LL j=0;j<a;j++){
			s[p+j]=c;
		}
		p+=a;
	}
	for(LL i=0;i<p/2;i++){
		if(s[i]!=s[p-1-i])
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}
