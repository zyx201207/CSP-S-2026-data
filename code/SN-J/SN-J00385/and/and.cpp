#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long n,m,maxx=0,cnt=0;
	cin>>n>>m;
	int a[n+1];
	for(long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long i=0;i<n;i++){
		for(long j=i+1;j<=m;j++){
			cnt=a[i]&a[j];
			if(maxx<cnt) maxx=cnt;
		}
	}
	cout<<maxx;
	return 0;
}
