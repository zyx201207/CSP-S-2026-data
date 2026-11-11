#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int c,t,n,d,a[2000005],cnt=0,f[5005][5005],plj[5005][5005],pminn[5005][5005];
int main(){
	freopen("migrate.out","w",stdout);
	freopen("migrate.in","r",stdin);
	cin >> c >> t;
	while(t--){
		cin >> n >>d;
		cnt=0;
		memset(f,0,sizeof(f));
		memset(plj,0,sizeof(plj));
		memset(pminn,0,sizeof(pminn));
		for (int i=1;i<=n;i++){
			cin >> a[i];
		}
		for (int i=1;i<=n;i++){
			for (int j=i+1;a[j]<=a[i]+d&&j<=n;j++){
				plj[i][j]++;
				pminn[i][j]=1;
				f[j][++f[j][0]]=i;
				for (int k=1;k<=f[i][0];k++){
					int ts=pminn[f[i][k]][i]+pminn[i][j];
					if(plj[f[i][k]][j]){
						if(pminn[f[i][k]][j]==ts){
							if(plj[f[i][k]][j]==2) cnt--;
							plj[f[i][k]][j]++;
							if(plj[f[i][k]][j]==2) cnt++;
						}else if(pminn[f[i][k]][j]>ts){
							if(plj[f[i][k]][j]==2) cnt--;
							plj[f[i][k]][j]=1;
							pminn[f[i][k]][j]=ts;
						}
					}else{
						plj[f[i][k]][j]=1;
						pminn[f[i][k]][j]=ts;
					}
				}
			}
		}
		cout << cnt << endl;
	}
} 
