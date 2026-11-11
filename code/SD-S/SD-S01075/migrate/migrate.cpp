#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int N=5e3+20;
int c,t,n,d,a[N],f[N][N],cnt,ans; 
vector<int> v;
void dfs(int l,int r,int jishu){
	if(l==r){
		v.push_back(jishu); 
		return;
	}
	for (int i=1;i<=d;i++){
		dfs(l+i,r,jishu+1);
	}
}
int main(){
	freopen("migrate,in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(f,0,sizeof(f));
		cin>>n>>d;
		for (int i=1;i<=n;i++){
			cin>>a[i];
		}
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				f[i][j]=min(f[i][j-2],f[i][j-1])+1; 
			}
		}
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				v.clear();
				dfs(i,j,0);
				cnt=0;
				for (int k=1;k<=v.size();k++){
					if(v[k]==f[i][j]){
						cnt++;
						if(cnt>=2){
							ans++;
							break;
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
