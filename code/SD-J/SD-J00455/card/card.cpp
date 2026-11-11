#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000000],b[1000000],sum[1000000];
int flag;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		flag=0;
		for(int i0=1;i0<=n;i++)
			b[i0]=0;
		for(int j=i;j<=n;j++){
			for(int k=1;k<=n;k++)
				if(a[j]==b[k]){
					flag=1;
					for(int q=k;q<=n;q++){
						b[q]=0;
						b[k]=a[j];
					}
				}
			if(flag==0)
				for(int k=1;k<=n;k++)
					if(b[k]==0){
						b[k]=a[j];
						break;
					}
		}
		for(int e=1;e<=m;e++)
			for(int j=1;j<=n;j++)
				if(b[j]==e){
					sum[e]++;
					break;
				}
	}
	for(int e=1;e<=m;e++)
		printf("%lld",sum[e]);
	return 0;
}
