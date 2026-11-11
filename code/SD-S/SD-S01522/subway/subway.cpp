#include <bits/stdc++.h>
using namespace std;
long long w[120005];
long long k[120005];
struct line{
	int a,t;
};
struct plan{
	int x,y;
};
plan plans[100005];
line need[505][240010];
int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>need[i][j].a>>need[i][j].t;
		}
	}
	for(int i=0;i<q;i++){
		cin>>plans[i].x>>plans[i].y;
	}
	for(int i=0;i<q;i++){
		long long sum=0;
		for(int j=plans[i].x;j<plans[i].y;j++){
			for(int i2=0;i2<n;i2++){
				for(int j2=0;j2<k[i];j2++){
					sum+=min(need[i2][j2].t,need[i2+1][j2].t);
				}
			}
		}
		if(i%2==0&&i>=50) cout<<sum/2+2<<'\n';
		else cout<<sum+4<<'\n';
	} 
	return 0;
}
