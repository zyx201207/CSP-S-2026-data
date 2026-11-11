#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],zh[500005],to[300005],tail=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		tail=1;
		for(long long j=i;j<=n;j++){
			long long f=0,t;
			for(long long k=1;k<=tail;k++){
				if(f==1){
					zh[k]=0;
				}
				if(zh[k]==a[j]){
					f=1;
					t=k;
				}
			}
			if(f==1){
				tail=t;
			}
			else{
				tail++;
				zh[tail]=a[j];
			}
		}
		for(long long j=1;j<=tail;j++){
			to[zh[j]]++;
			//cout<<zh[j]<<" ";
		}
		//cout<<endl;
	}
	for(long long i=1;i<=m;i++){
		cout<<to[i]<<" ";
	}
	
	return 0;
}
/*
4 3
1 2 1 3
*/
