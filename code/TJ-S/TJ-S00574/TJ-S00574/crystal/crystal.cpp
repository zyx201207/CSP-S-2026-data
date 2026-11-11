#include<bits/stdc++.h>
using namespace std;
bool cmp(long long q,long long w){
	return q<w;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,mx=1,a[80000],cf[80000],ch[80000];
	cin>>n>>m;
	for (long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for (long long i=0;i<n-1;i++){
		cf[i]=a[i+1]-a[i];
	}
	for (long long i=0;i<n-1;i++){
		ch[i]=cf[i]*(i+1)+ch[i-1];
	}
	if (ch[0]<m) mx=2;
	for (long long i=0;i<n-1;i++){
		for (long long j=i+mx;j<n;j++){
			if (i!=0){
				if (ch[j-1]-ch[i-1]-(a[j]-a[i])*i<m && j-i+1>mx){
					mx=j-i+1;
				}
			}
			else{
				if (ch[j-1]<=m && j+1>mx){
					mx=j-i+1;
				}				
			}
		}
	}
	printf("%.lld",mx);
	return 0;
}
