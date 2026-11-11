#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
long long c,t,n,d;
long long a[2000005];
int vst[2000005]={0};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int cnt=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=i;k<=j;k++){
					vst[k]=0;
				}
				vst[i]=1;
				queue<int>q;
				q.push(i);
				int ans=0;
				int minn=1000000005;
				while(q.size()){
					int u=q.front();
					q.pop();
					if(u==j){
						++ans;
						if(ans>2){
							break;
						}
						continue;
					}
					for(int k=u+1;k<=n;k++){
						if(a[k]-a[u]>d){
							break;
						}
						if(vst[k]&&vst[k]<vst[u]+1){
							continue;
						}
						q.push(k);
						vst[k]=vst[u]+1;
					}
				}
				if(ans==2){
					++cnt;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
