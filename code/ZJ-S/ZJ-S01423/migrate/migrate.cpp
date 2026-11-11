#include<bits/stdc++.h>
using namespace std;
int x[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d,ans=0;;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				int cnt=0,minn=0x3f3f3f3f;
				queue<pair<int,int> >q;
				q.push({i,0});
				while(!q.empty()){
					pair<int,int>o=q.front();
					q.pop();
					int c=o.first,v=o.second;
					if(c==j){
						if(v<minn){
							minn=v;
							cnt=1;
						}else if(v==minn){
							cnt++;
						}
					}
					for(int k=c+1;k<=j;k++){
						if(x[k]-x[c]>d)break;
						q.push({k,v+1});
					}
				}
				if(cnt==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
