#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k,pass,num,start,end,mn;
long long w[1000000],a[505][500005],t[505][500005];
void timemn(int x,int y){
	for(int i=1;i<=n;i++){
		if(a[i][x]==true){
			if(a[i][y]==true){
				mn=w[x]+w[y];
				return;
			}
			for(int j=1;j<=d;j++){
				for(int k=1;k<=m;k++){
					if(a[i][j]==true&&a[k][j]==true){
						long long tm=t[i][j]+t[k][j];
						mn=min(mn+w[x]+w[y],tm+w[x]+w[y]);
					} 
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%ld%ld%ld%ld%ld",&c,&n,&m,&d,&q);
	for(int i=1;i<=n;i++){
		scanf("%ld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%ld",&k);
		for(int j=1;j<=k;j++){
			scanf("%ld%ld",&pass,&num);
			a[i][pass]=true;
			t[i][pass]=num;
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%ld%ld",&start,&end);
		timemn(start,end);
		printf("%ld",mn);
		cout<<endl;
    }
	return 0;
}