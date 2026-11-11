//SN-J00756 程谟然 西安建筑科技大学附属中学 
#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long corn[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long t=1;t<=m;t++){
		bool Cathy[500005]={};
		for(long long i=t+1;i<=n;i++){
			for(long long j=t;j<i;j++){
				if(a[i]==a[j]&&Cathy[j]==0){
					for(long long c=j;c<=i-1;c++){
						Cathy[c]=1;
					}
				}
			}
		}
		for(long long i=1;i<=n;i++){
			if(Cathy[i]!=1){
				corn[a[i]]++;
			}
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<corn[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
