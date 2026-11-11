#include<bits/stdc++.h>
#define ll long long
#define sc scanf
#define pf printf
using namespace std;
int n,m,ans[300005],card[500005],r[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	sc("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		sc("%d",&card[i]);
		//r[i]=card[i];
	}
	for(int x=1;x<=n;x++){
		for(int i=x;i<=n;i++){
			r[i]=card[i];
			for(int j=x;j<=i;j++){
				if(r[j]==0)continue;
				if(card[j]==card[i]){
					for(int k=j;k<i;k++)r[k]=0;
				}
			}
		}
		for(int i=x;i<=n;i++){
			ans[r[i]]++;
			r[i]=card[i];
		}
	}
	for(int i=1;i<=m;i++){
		pf("%d ",ans[i]);
	} 
	return 0;
} 
