#include<bits/stdc++.h>
using namespace std;
struct s{
	int a,c;
}a[200020];
long long n,m,sum[200020],maxx=0xcfcfcfcfcfcfcfcf;
int count(int k){
	int cnt=0;
	while(k){
		if(k%2==1){
			cnt++;
		}
		k>>=1;
	} 
	return cnt;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].a;
		a[i].c=count(a[i].a);
	}
	if(m==n-1){
		int k1=a[1].a,k2=a[2].a;
		for(int i=2;i<=m;i++){
			k1&=a[i].a;
		}
		for(int i=3;i<=n;i++){
			k2&=a[i].a;
		}
		cout<<max(k1,k2);
	}
	for(int i=1;i<=n;i++){
		sum[i]=a[i].a;
		for(int j=i+1;j<=i+m-1;j++){
			long long maxn=0xcfcfcfcfcfcfcfcf,maxi;
			for(int k=i+1;k<=n;k++){
				if(maxn<a[k].c){
					maxn=a[k].c;
					maxi=k;
				}
			}
			sum[i]&=a[maxi].a;
		}
		maxx=max(maxx,sum[i]);
	}
	cout<<maxx;
	return 0;
}

