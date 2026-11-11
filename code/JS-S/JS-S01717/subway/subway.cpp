#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans;
int a[505][1000000];
int b[1000000];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d",&c);
	scanf("%d",&n);
    scanf("%d",&m);
    scanf("%d",&d);
    scanf("%d",&q);
    for(int i = 1;i<=m;i++)scanf("%d",&b[i]);
    for(int i = 1;i<=n;i++){
		int num;
		scanf("%d",&num);
		for(int j = 1;j<=num;j++){
			int p;
			scanf("%d",&p);
			scanf("%d",&a[i][p]);
		}
	}
	for(int i = 1;i<=q;i++){
		int st,fi;
		scanf("%d",&st);
		scanf("%d",&fi);
		ans = 0x3f3f3f;
		for(int j = 1;j<=n;j++)if(a[j][st]!=0 && a[j][fi]!=0) ans = min(ans,b[st]+b[fi]+a[j][st]+a[j][fi]);
		for(int k = 1;k<n;k++){
			if(a[k][st]!=0 && a[k][fi]==0){
				for(int g = k+1;g<=n;g++){
					if(a[g][st]==0 && a[g][fi]!=0){
						for(int l = 1;l<=m;l++)if(l!=st && l!=fi && a[k][l]!=0 && a[g][l]!=0)ans = min(ans,b[st]+b[fi]+a[k][st]+a[k][l]+a[g][l]+a[g][fi]);
					}
				}
			}
		}
		printf("%d",ans);
		cout<<endl;
	}
	return 0;
}
