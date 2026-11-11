#include<bits/stdc++.h>
using namespace std;
const long long N=100000005;
int n;
long long g[N],sum=0;
char b[N];
char a[N],f[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>g[i]>>b[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=g[i];j++){
			a[i]=b[i];
			f[i]=a[i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=n;j>=1;j--){
		    if(f[j]!=a[i]) sum++;
	    }
	}
	cout<<sum/n;
	return 0;
}
