#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,a[500005]={},b[500001]={};
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	b[1]=a[1];
	boor f=0;
	int cnt=0;
	for(long long i=2;i<=n;i++){
		for(long long j=2;j<=n;j++){
			f=0;
			if(a[i]==b[j]){
				for(long long r=j;j<=n;j++){
					b[r]=0;
					break;
				}
			}
			else{
				f=1;
			}
		}
		if(f=1){
			for(long long j=2;j<=n;j++){
				if(b[j]==0){
					b[j]=a[i];
				}
			}
		}
		for(long long j=1;j<=m;j++){
			for(long long j=1;j<=n;j++){
				if(b[j]==i)cnt++;
			}
		}
		cout<<cnt<<" ";
	}
}
