#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int b[500005];
int c[500005];
long long n;
unsigned long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	c[1]=1;
	for(int i=2;i<=n;i++){
		int www=(i-1)*a[i]-b[i-1];
		if(www<=m){
			c[i]=i;
			continue;
		}
		int l=0,r=i-1,mid=(l+r)/2;
		while(r-l!=1){
			int w=(i-1-mid)*a[i]-(b[i-1]-b[mid]);
			if(w<m){
				r=mid;
				mid=(l+r)/2;
			}
			else if(w>=m){
				l=mid;
				mid=(l+r)/2;
			}
		}
		c[i]=i-r;
	}
	int maxx=0;
	for(int i=1;i<=n;i++){
		if(c[i]>maxx){
			maxx=c[i];
		} 
	}
	cout<<maxx;
	return 0;
}
