#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500009],b[300009];
queue <int> q;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%ld%ld",n,m);
	for(int i=1;i<=n;i++){
		scanf("%ld",a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			q.push(a[i]);
			for(int k=1;k<q.size();k++){
				if(q.size()!=1){
					for(int l=0;l<k;l++){
						q.pop();
					}
				}
			}
		}
		while(q.size()){
			b[q.front()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i];
	}
	
	return 0;
}
