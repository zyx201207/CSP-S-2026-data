#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],mx=-99,mx2,b[1000005],bb,c[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		int noer=0;
		bb=0;
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			bool f=0;
			int xiabiao=0;
			for(int k=1;k<=bb;k++){
				if(a[j]==b[k]){
					f=1;
					xiabiao=k;
					break;
				}
			}
			if(f==0){
				b[++bb]=a[j];
			}
			else if(f==1){
				int cnt=0;
				for(int o=xiabiao;o<=bb;o++){
					cnt++;
					b[o]=0;
				}
				bb-=cnt;
				b[++bb]=a[j];
			}
		}
		for(int j=1;j<=bb;j++){
			c[b[j]]++;
		}
	}
	for(int j=1;j<=m;j++){
		cout<<c[j]<<" ";
	}
	return 0;
}
