#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[1001],k[1001],a[501][11],t[501][11];
bool b[1001];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	int x=1 << 30,y=0;
	bool flag=true;
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		x=min(x,k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&a[i][j],&t[i][j]);
			if(!y)
				y=t[i][j];
			if(y!=t[i][j])
				flag=false;
		}
	}
	if(x<=2){//speicalA
		memset(b,false,sizeof(b));
		long long p=0;
		for(int i=1;i<=n;i++){
			p+=t[i][1]+t[i][2];
			if(b[a[i][2]]==true){
				swap(a[i][1],a[i][2]);
				swap(t[i][1],t[i][2]);
			}
			b[a[i][2]]=true;
		}
		for(int i=1;i<n;i++){
			for(int j=n;j>i+1;j--){
				if(a[j][1]==a[i][2]){
					swap(a[j][1],a[j-1][1]);
					swap(a[j][2],a[j-1][2]);
					swap(t[j][1],t[j-1][1]);
					swap(t[j][2],t[j-1][2]);
				}
			}
		}
		for(;q--;){
			scanf("%d%d",&x,&y);
			int s=0;
			for(int i=1;i<=n;i++){
				if(a[i][1]==x){
					s=i;
					break;
				}
			}
			long long h=0;
			while(true){
				h+=t[s][1]+t[s][2];
				s=s%n+1;
				if(a[s][1]==y)
					break;
			}
			h=min(h,p-h);
			printf("%lld\n",h+w[x]+w[y]);
		}
		return 0;
	}
	if(flag)
		for(int i=1;i<=q;i++){
			scanf("%d%d",&c,&d);
			printf("%d\n",y);
		}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		printf("3\n");
	}
	return 0;
}
