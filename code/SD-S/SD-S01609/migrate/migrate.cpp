#include<bits/stdc++.h>
using namespace std;
int c,t,a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		long long cnt=0;
		for(int len=4;len<=n;len++){
			for(int i=1;i+len-1<=n;i++){
				int j=i+len-1;
				if(a[j]-a[i]>2*m){
					continue;
				}
				cnt++;
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}

