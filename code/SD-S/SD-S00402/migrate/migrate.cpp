#include<bits/stdc++.h>
using namespace std;
long long x[2000010];
int d[2000010];
int s[2000010];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
int main(){
	ios::sync_with_stdio(nullptr);
	cin.tie(false);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	int C,T,n,D;
	cin>>C>>T;
	long long ans;
	while(T--){
		cin>>n>>D;
		vector<vector<int>> v(n+1);
		for(int i=1;i<=n;i++){
			cin>>x[i];
			for(int j=i-1;j>=1;j--){
				if(x[i]-x[j]>D){
					break;
				}
				v[j].push_back(i);
			}
		}
		int a,b;
		ans=0;
		for(int i=1;i<=n;i++){
			q.push({0,i});
			memset(d,0x3f,sizeof(d));
			memset(s,0,sizeof(s));
			d[i]=0;
			while(!q.empty()){
				a=q.top().second;
				b=q.top().first;
				q.pop();
				if(b>d[a]){
					continue;
				}
				for(const int c:v[a]){
					if(b+1<d[c]){
						d[c]=b+1;
						q.push({d[c],c});
						s[c]=0;
					}else if(b+1==d[c]){
						s[c]++;
					}
				}
			}
			for(int j=1;j<=n;j++){
				if(s[j]==1){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
