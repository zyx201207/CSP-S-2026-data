#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001][50],b[200001],top=0,cnt=0;
bool c[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		int t=0;
		while(x!=0){
			a[i][++t]=x%2;
			x/=2;
		}
	}
	memset(c,true,sizeof(c));
	for(int i=50;i>=1;i--){
		int x=0;
		for(int j=1;j<=n;j++){
			if(c[j] && a[j][i]==1)
				x++;
		}
		if(x>=m){
			cnt+=1 << (i-1);
			for(int j=1;j<=n;j++){
				if(!a[j][i])
					c[j]=false;
			}
		}
	}
	printf("%d\n",cnt);
}
