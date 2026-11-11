#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],b=0,p,m1[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long ji=0;ji<n;ji++)cin>>a[ji];
	for(long long ji=0;ji<n;ji++){
	for(long long i=ji;i<n;i++){
	p=a[i];
		
		for(long long j=0;j<b;j++){
			if(a[j]==p){
				for(long long l=0;l<b;l++){
					a[l]=0;
				}
				b=0;
			}
		}
		a[b]=p;
		b++;
	}
	
		for(long long l=0;l<m;l++){
			for(long long j=0;j<b+1;j++){
				if(a[j]==l+1){
					m1[l]++;
					break;
				}
			}
		}
	}
	for(long long i=0;i<m;i++){
		cout<<m1[i]<<' ';
	}
}
