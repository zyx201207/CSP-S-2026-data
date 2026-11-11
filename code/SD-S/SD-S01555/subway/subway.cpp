#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,ans;
long long st[500005];
struct station{
	long long line[25];
	long long time[25];
};
station ss[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i<=m;i++){
		cin >> st[i];
	}
	for(int i = 1;i<=n;i++){
		int cnt;
		cin >> cnt;
		for(int j = 1;j<=cnt;j++){
			int num;
			cin >> num;
			ss[num].line[i] = i;
			cin >> ss[num].time[i];
		}
	}
	while(q--){
		int s,e;
		cin >> s >> e;
		for(int i = 1;i<=m;i++){
			long long minn = 0;
			for(int j = 1;j<=n;j++){
				if(ss[i].line[j]!=0)
				minn = ss[i].time[j];
				break;
			}
			ans+=minn;
		}
		cout << ans+st[s]+st[e] << endl;
		ans = 0;
	}
	return 0;
}
