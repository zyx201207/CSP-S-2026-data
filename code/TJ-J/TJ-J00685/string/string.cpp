#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
long long n,a[N],ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(long long j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	long long lens=s.size();
	string x=s;
	reverse(x.begin(),x.end());
	for(long long i=0;i<lens;i++){
		if(x[i]!=s[i]) ans++;
	}
	ans/=2;
	cout<<ans;
	return 0;
}
