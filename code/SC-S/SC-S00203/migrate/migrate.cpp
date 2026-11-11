#include <bits/stdc++.h>
using namespace std;

const int N=2e6+100;
int c,T,n;
long long d,x[N];

vector <int> e[N];

int dep[N],tmp,cnt[N];
long long ans=0;
queue <int> q1;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		scanf("%d%lld",&n,&d);
		for(int i=1; i<=n; i++){
			scanf("%lld",&x[i]);
			e[i].clear();
			ans=0;
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n&&x[j]-x[i]<=d; j++){
				e[i].push_back(j);
				//cout<<i<<" "<<j;
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				dep[j]=100000000,cnt[j]=0;
			}
			dep[i]=1,cnt[i]=1;
			while(!q1.empty())q1.pop();
			q1.push(i);
			while(!q1.empty()){
				tmp=q1.front();
				//cout<<tmp<<endl;
				q1.pop();
				for(int x:e[tmp]){
					if(dep[x]==dep[tmp]+1){
						cnt[x]+=cnt[tmp];
						q1.push(x);
					//	if(x==2)cout<<tmp<<"git";
					}else if(dep[x]>dep[tmp]+1){
						dep[x]=dep[tmp]+1;
						cnt[x]=1; 
						q1.push(x);
						//if(x==2)cout<<tmp<<"gdf";
					}
				}
			}
			
//			for(int j=1; j<=n; j++)cout<<cnt[j]<<" ";
//			cout<<endl;
			
			for(int j=1; j<=n; j++){
				if(cnt[j]==2){
					ans++;
					//cout<<"("<<i<<" "<<j<<")"<<endl;
				}
			} 
		} 
		printf("%lld\n",ans);
	} 
	return 0; 
}