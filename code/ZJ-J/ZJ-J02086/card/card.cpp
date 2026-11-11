#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int kl[500005],l=0,ste=0;
int tong[500005],js[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; ++i){
		scanf("%d",&a[i]);
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; j++){
			js[j]+=tong[j];
			kl[j]=0;
			tong[j]=0;
		}
		ste=0;
		
		for(int j = i; j <= n; j++){
			kl[++ste]=a[j];
			if(tong[a[j]]){
				bool uv=0;
				for(int k = 1; k<= ste-1; k++){
					if(kl[k]==a[j]||uv){
						tong[kl[k]]--;
						kl[k]=0;
						uv=1;
					}
				}
			}
			
			tong[a[j]]++;
		}
	}
	js[a[n]]++;
	for(int i = 1; i <= m; ++i){
		//cout<<js[i]<<" ";
		printf("%d ",js[i]);
	}
	return 0;
}
