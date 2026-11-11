#include<bits/stdc++.h>
using namespace std;

int c = 0,n = 0,m = 0,d = 0,q = 0;
int station[500001] = {0};
int line[501][500001] = {0};
int plan[100001][2] = {0};

int answer(int x){
	int ans = 0;
	int first = plan[x][1],last = plan[x][2];
	if (first==last){
		return 0;
	}
	ans += station[first] + station[last];
	ans += line[first][first];
	for (int j=first;j<=m;j++){
		if (j>n){
			if (j==last){
				ans += line[first][j];
				break;
			}
		}
		else if (first<j){
			if (j==last){
				ans += line[first][j];
				break;
			}
			else{
				ans += line[first][j] + line[j][j];
				first = j;
			}
		}
	}
	return ans;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i=1;i<=m;i++){
		cin >> station[i];
	}
	for (int i=1;i<=n;i++){
		int num = 0;
		cin >> num;
		for (int j=1;j<=num;j++){
			int goal = 0,time = 0;
			cin >> goal >> time;
			line[i][goal] = time;
		}
	}
	for (int i=1;i<=q;i++){
		cin >> plan[i][1] >> plan[i][2];
	}
	for (int i=1;i<=q;i++){
		if (i!=q){
			cout << answer(i) << endl;
		}
		else{
			cout << answer(i);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
