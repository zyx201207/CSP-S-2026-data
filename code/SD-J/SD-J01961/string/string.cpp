#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N],b[N];
char c[N],d[N];
string s,p;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	for(int i=1,j=n;i<=n,j>=1;i++,j--){
		cin>>a[i]>>c[i];
		b[j]=a[i],d[j]=c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
		for(int j=1;j<=b[i];j++){
			p+=d[i];
		}
	}
	for(int i=0;i<=s.size();i++){
		if(s[i]!=p[i]) ans++;
	}
	cout<<ans/2<<'\n';
	return 0;
}
