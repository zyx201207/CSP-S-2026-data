#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("subway.in","r",stdin); 
    //freopen("subway.out","w",stdout);

    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    int time[m];
	int ans;
    int total[n][10000];
    int way[n][10000];
    int way_time[n][10000];
    int ix[n];
    int plan[q][2];
	for (int i = 0;i < m;i ++){
		cin >> time[i];
	}
	for (int i = 0;i < n;i ++){
		cin >> ix[i];
		for (int j = 0;j < ix[i]*2;j ++){
			cin >> total[i][j];
		}
	}
	for (int i = 0;i < n;i ++){
		for (int j = 0;j < ix[i];j++){
			way[i][j] = total[i][j*2];
			way_time[i][j] = total[i][j*2+1];
		}
	}
	
	for (int r = 0;r < q;r ++){
		for (int i = 0;i < 2;i ++){
			cin >> plan[r][i];
		}
	}
	
	
	for (int i = 0;i < n;i++){
		for (int j = 0;j < ix[i];j ++){
			if (){
				
			}
		}
	}
} 
