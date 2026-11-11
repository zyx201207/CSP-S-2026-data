#include <bits/stdc++.h>
using namespace std;



int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	int chu[m+5];
	for(int i=1;i<=m;i++) cin >> chu[i];
	int lg[n+2][m+2];
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		for(int j=1;j<=k;j++){
			int lgd;
			cin >> lgd;
			cin >> lg[i][lgd];
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	for(int i=1;i<=q;i++){
		int qd,zd,sj=0;
		cin >> qd >> zd;
		for(int j=1;j<=m;j++){
			if(lg[1][j]==0) continue;
			if(lg[1][j]!=0){
				for(int v=1;v<=m;v++){
					if(lg[j][v]==0) continue;
					if(lg[j][v]!=0){
						for(int h=1;h<=m;h++){
							
						}
					}
				} 
			}
		}
		sj+=chu[qd];
		sj+=chu[zd];
		cout << sj << "\n";
	}
	
	return 0;
} 
