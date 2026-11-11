#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card2.in","r",stdin);
	freopen("card.out","w",stdout);
    
	long long n,m;
	cin>>n>>m;
	long long a[n+5],b[n+5]={0};
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=m;i++){
		long long c[n+5],c1=1;
		for(long long j=1;j<=n;j++){
			for(int y=c1;y>=1;y--){
				if(a[i]==c[y]){
					c1==y+1;
					break;
				}
			}
			c[c1]=a[i];
		}
		for(int j=1;j<=c1;j++){
			b[c[j]]++;
//			cout<<c[j]<<" ";
		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	
	return 0;
}
