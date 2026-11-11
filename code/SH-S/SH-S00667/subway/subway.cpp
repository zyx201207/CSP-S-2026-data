#include<bits/stdc++.h>
#define MAXN 500005
#define MAXXN 10000000000000000
using namespace std;
int c,n,m,d,q,A,T,X,Y,II,JJ,gd,fir;
long long ans,ANS,dis[4];
int w[505],k[MAXN];
vector<int>a[MAXN];
vector<long long>t[MAXN];

void cz1(int x,int y){
	if(fir == 1){
		dis[1] = MAXXN;
	dis[2] = MAXXN;
	dis[3] = MAXXN;
	for(int i = 1;i <= m;i++){
		if(a[i].size() == 3){
			if(a[i][0] == 3){
				gd = t[i][0];
				t[i][0] = t[i][2];
				t[i][2] = gd;
				a[i][0] = a[i][2];
				a[i][2] = 3;
			}
			if(a[i][1] == 3){
				gd = t[i][1];
				t[i][1] = t[i][2];
				t[i][2] = gd;
				a[i][1] = a[i][2];
				a[i][2] = 3;
			}
			if(a[i][0] == 2){
				gd = t[i][0];
				t[i][0] = t[i][1];
				t[i][1] = gd;
				a[i][0] = a[i][1];
				a[i][1] = 2;
			}
			dis[1] = min(dis[1],t[i][1]+t[i][0]);
			dis[2] = min(dis[2],t[i][1]+t[i][2]);
			dis[3] = min(dis[3],t[i][2]+t[i][0]);
		}
		if(a[i].size() == 2){
			if((a[i][0] == 1&&a[i][1] == 2)||(a[i][1] == 1&&a[i][0] == 2))dis[1] = min(dis[1],t[i][1]+t[i][0]);
			if((a[i][0] == 1&&a[i][1] == 3)||(a[i][1] == 1&&a[i][0] == 3))dis[3] = min(dis[3],t[i][1]+t[i][0]);
			if((a[i][0] == 3&&a[i][1] == 2)||(a[i][1] == 3&&a[i][0] == 2))dis[2] = min(dis[2],t[i][1]+t[i][0]);
		}
	}
	dis[1] = min(dis[1],dis[2]+dis[3]);
	dis[2] = min(dis[2],dis[1]+dis[3]);
	dis[3] = min(dis[3],dis[2]+dis[1]);
	fir = 0;
	}
	if((x == 1&&y == 2)||(x == 2&&y == 1))ans = dis[1];
	if((x == 3&&y == 2)||(x == 2&&y == 3))ans = dis[2];
	if((x == 1&&y == 3)||(x == 3&&y == 1))ans = dis[3];
}

void cz4(int x,int y){
	if(fir == 1){
		dis[1] = MAXXN;
		for(int i = 1;i <= m;i++){
			if(a[i].size() == 2){
				dis[1] = min(dis[1],t[i][0]+t[i][1]);
			}
		}
		fir = 0;
	}
	ans = dis[1];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
fir = 1;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= n;i++)cin >> w[i];
	for(int i = 1;i <= m;i++){
		cin >> k[i];
		for(int j = 0;j < k[i];j++){
			cin >> A >> T;
			a[i].push_back(A);
			t[i].push_back(T);
		}
	}
	for(int Q = 0;Q < q;Q++){
		ans = 0;
		cin >> X >> Y;
		if(c >= 1&&c <= 3)cz1(X,Y);

		if(c >= 20&&c <= 21)cz4(X,Y);

		ANS = ans + w[X] + w[Y];
		cout << ANS << "\n";
	}
	return 0;
}
