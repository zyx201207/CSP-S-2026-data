#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],dep,vis[200005];
long long ans;
vector<int> v[35];
void split(int a,int id){
	int cnt=1;
	while(a){
		if(a&1){
			v[cnt].push_back(id);
		}
		a>>=1;
		cnt++;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		split(a[i],i);
	}
	for(int i=32;i>=0;i--){
		if(v[i].size()<=0) continue;
		if(v[i].size()>=m){
			int cnt=0;
			for(int j=0;j<v[i].size();j++){
				if(vis[v[i][j]]==dep){
					cnt++;
				}
			}
			if(cnt>=m){	
				ans+=(1<<(i-1));
				for(int j=0;j<v[i].size();j++){
					if(vis[v[i][j]]==dep){
						vis[v[i][j]]++;
					}
				}
				dep++;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
