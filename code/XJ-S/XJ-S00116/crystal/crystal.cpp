#include<bits/stdc++.h>
using namespace std;

#define N 500005
int c[N],y[N];
int maxn=-100000005;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n,m,cnt=0;
	scanf("%d %d",&n,&m);
	
	for(int i=1;i<=n;++i){
		scanf("%d",y[i]);
	}
	
	int ym=m;
	
	for(int i=1;i<=n;++i){
		ym=m;
		
		for(int j=1;j<=n;++j){
			ym=y[i]-y[j];
			
			if(ym<=0){
				break;
			}else{
				c[i]+=1;
			}
		}
		
	}
	
	for(int i=1;i<n;++i){
		if(c[i]<=maxn){
			maxn=c[i];
		}
	}
	cout<<maxn;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
