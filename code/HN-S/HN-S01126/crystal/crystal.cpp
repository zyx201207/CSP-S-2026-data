#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=1e5+10;
long long a[N],b[M],c[N];
long long n,m,ans;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		b[c[i]]++;
	}
	long long h=0;
	for(int i=1;i<=n+h;i++){
		int f=0;
		if(b[c[i]]%2!=0)  f=1;
		if(b[c[i]]>1){
			c[h]=c[i]*2;
			b[c[i]*2]+=b[c[i]]/2;
			ans+=b[c[i]]/2;
			b[c[i]]=f;
			h++;
		}		
	}
	long long h1=1;
	for(int i=1;i<=h+n;i++){
		if(c[i]==1){
			a[h1]=c[i];
			h1++;
		}
	}
	sort(a+1,a+h1+1);
	for(int i=1;i<=h1;i++)cout<<a[i]<<" ";
	cout<<ans+1;
	return 0;
} 
