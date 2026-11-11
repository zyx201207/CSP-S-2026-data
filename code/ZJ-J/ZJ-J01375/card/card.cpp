#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],f,t[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int k=1;k<=n;k++){
		memset(b,0,sizeof(b));
		for(int i=k;i<=n;i++){
			f=0;
			for(int j=1;j<=i;j++){
				if(b[j]==a[i]){
					f=1;
				}
				if(f==1){
					b[j]=0;
				}
			}
			b[i]=a[i];
		}
		for(int i=1;i<=n;i++){
			t[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",t[i]);
	}
	return 0;
}