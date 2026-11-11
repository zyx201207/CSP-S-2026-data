#include <bits/stdc++.h>
using namespace std;
template<typename T> using vec=vector<T>;
constexpr long long INF=0x1fffffffffffffff;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;
		long long d;
		cin>>n>>d;
		bool flag=1;
		vec<long long> x(n);
		for(int i=0;i<n;i++){
			cin>>x[i];
			if(i>1 and x[i]-x[i-1]!=x[i-1]-x[i-2]){
				flag=0;
			}
		}
		if(n>5000 and flag==1){
			long long s=x[1]-x[0];
			if(d<=s or d>=x[n-1]-x[0]) cout<<0<<endl;
			else cout<<max(0ll,n-d/s*2+1)<<endl;
			continue;
		}
		long long ans=0;
		for(int j=0;j<n;j++){
			vec<vec<long long>> dis(n,vec<long long>(3,INF));
			dis[j][0]=0;
			for(int i=j+1;i<n;i++){
				for(int qq=i-1;qq>=j and x[i]-x[qq]<=d;qq--){
					if(dis[qq][0]+1<dis[i][0]){
						dis[i][2]=dis[i][1];
						dis[i][1]=dis[i][0];
						dis[i][0]=dis[qq][0]+1;
					}else if(dis[qq][0]+1<dis[i][1]){
						dis[i][2]=dis[i][1];
						dis[i][1]=dis[qq][0]+1;
					}else if(dis[qq][0]+1<dis[i][2]){
						dis[i][2]=dis[qq][0]+1;
					}
					if(dis[qq][1]+1<dis[i][0]){
						dis[i][2]=dis[i][1];
						dis[i][1]=dis[i][0];
						dis[i][0]=dis[qq][1]+1;
					}else if(dis[qq][1]+1<dis[i][1]){
						dis[i][2]=dis[i][1];
						dis[i][1]=dis[qq][1]+1;
					}else if(dis[qq][1]+1<dis[i][2]){
						dis[i][2]=dis[qq][1]+1;
					}
					if(dis[qq][2]+1<dis[i][0]){
						dis[i][2]=dis[i][1];
						dis[i][1]=dis[i][0];
						dis[i][0]=dis[qq][2]+1;
					}else if(dis[qq][2]+1<dis[i][1]){
						dis[i][2]=dis[i][1];
						dis[i][1]=dis[qq][2]+1;
					}else if(dis[qq][2]+1<dis[i][2]){
						dis[i][2]=dis[qq][2]+1;
					}
				}
			}
			for(int i=j;i<n;i++){
				if(dis[i][0]==dis[i][1] and dis[i][0]!=dis[i][2]){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	cout.flush();
	return 0;
}
