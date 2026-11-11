#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y,k,sdt,sdtz,edt,edtz,cd,dc;
int w[500005];
struct fb{
	int o;
	int p;
}fb[500005];
long long ans;
struct b{
	int a;//地铁站 
	int t;//时间 
}b[505][500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		cin >> k;
		for(int j=1;j<=k;i++){
			cin >> b[i][j].a >> b[i][j].t;
			if(b[i][j].t<b[fb[b[i][j].a].o][fb[b[i][j].a].p].t){
				fb[b[i][j].a].o=i;//用时最短的a的数值站的地铁
				fb[b[i][j].a].p=j;//用时最短的a的数值站的地铁第几站 
			}
		}
	}
	while(q--){
		cin >> x >> y;
		ans+=w[x]+w[y];
		ans+=b[fb[x].o][fb[x].p].t;
		sdt=fb[x].o;
		sdtz=fb[x].p;
		edt=fb[y].o;
		edtz=fb[y].p;
		if(n<=2){
			while(1){
				if(sdt==edt){
					sum+=w[sdt][sdtz]+w[edt][edtz];
					cout << sum << endl;
					break;
				}
				else{
					for(int i=1;i<=500005;i++){
						for(int j=1;j<=500005;j++){
							if(b[1][i].a==b[2][j].a){
								sum+=b[1][i].t+b[2][j].t;
								sdt=2;
								sdtz=j;
							}	
						}
					}
				}
			}
		}
		else{
			while(1){
				if(sdt==edt){
					sum+=w[sdt][sdtz]+w[edt][edtz];
					cout << sum << endl;
					break;
				}
				else{
					sum+=b[sdt][1].t+b[sdt][2].t;
				}
			}
		} 
	}
	return 0;
}
