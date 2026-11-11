#include <iostream>
#include <stdio.h>
using namespace std;

int w[500005];
int tl[505][1005];
int xy[100005][2];
bool lx[505][1005];

int main()
{
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	
	int c,n,m,d,p;
	cin >> c >> n >> m >> d >> p;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin >> a >> t;
			tl[i][a]=t;
			lx[i][a]=1;
		}
		tl[i][0]=k;
	}
	for(int i=0;i<p;i++){
		cin >> xy[i][0] >> xy[i][1];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(tl[i][j]==0){
				for(int k=1;k<=n;k++){
					if(tl[k][j]){
						for(int g=0;g<=m;g++){
							if(tl[k][g] && tl[k][i]){
								tl[i][j]=(tl[i][j]?
										min(tl[i][j],tl[k][g]+tl[k][i]):
										tl[k][g]+tl[k][i]);
							}
						}
					}
				}
			}
		}
	}
	for(int i=0;i<p;i++){
		cout << tl[xy[i][0]][xy[i][1]]; 
	}
	
	return 0;
}