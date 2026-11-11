#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<vector>
using namespace std;
const int N=2e5+5;
long long n, len, cnt;
long long minn, h1, h2;
long long a[N], b[N];
char c[N], d[N];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1; i<=n; ++i){
		cin>>a[i]>>c[i];
		len+=a[i];
		b[n+1-i]=a[i];
		d[n+1-i]=c[i];
	}
	a[n+1]=b[n+1]=1e9; 
	long long i=1;
	h1=h2=1;
	while(i<=len/2){
		minn=min(a[h1],b[h2]);
//		cout<<h1<<' '<<h2<<'\n';
//		cout<<a[h1]<<' '<<b[h2]<<'\n';
		if(c[h1]!=d[h2]){
			cnt+=minn;
//			cout<<minn<<' '<<i<<'\n';
		}
		if(a[h1]==minn){
			++h1;
		} else{
			a[h1]-=minn;
		}
		if(b[h2]==minn){
			++h2;
		} else{
			b[h2]-=minn;
		}
		i+=minn;
	}
	cout<<cnt<<'\n';
	return 0;
}

