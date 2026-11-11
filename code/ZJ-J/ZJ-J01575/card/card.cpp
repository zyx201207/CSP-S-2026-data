#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],f[10000];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	//printf("Hello World!");
	int q=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(f.find(a[j])=="EOF"){
				f[j]=a[j];
				q++;
			}else{
				Q=f.find(a[j]);
				f.erase(f.find(a[j])+1,f.length());
			}
		}
	}
	return 0;
}
//I am almost asleep,fall into a forever sleeping...Zzz
