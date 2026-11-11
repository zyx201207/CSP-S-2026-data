#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,st_num,db,time_tdt;
long long alt = 0;
int time_kdt[500050];int arr[550][500050];
void se(int sta,int fin){
	for(int i = 1;i<=n;i++){
		
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i<=m;i++){
		cin >> time_kdt[i];
	}

	for(int i = 1;i<=n;i++){
		cin >> st_num;
		for(int j = 1;j<=st_num;j++){
			cin >> db >> time_tdt;
			arr[i][db] = time_tdt+time_kdt[db];
		}
	}
	int start = 0;int finish = 0;
	while(q--){
		cin >> start >> finish;
		se(start,finish);
	}
	return 0;
}

