#include<iostream> 
#include<cstdio>
using namespace std;
int c, n, m, d, q ;
int a[507][500007],s[500007],az[507],z[107][107];//;
bool p[500007];
int ans=99999999;

void dfs(int step,int f,int e){
	if(f>=ans)return;
	if(step==e){
		ans=min(f,ans);
		return;
	}
	for(int i=1;i<=n;i++){//cout<<step<<" ";
		for(int k=0;k<az[i];k++){
			if(z[i][k]==step){
				p[step]=1;
				for(int j=1;j<=az[i];j++){
					if(!p[z[i][j]]){
						
						dfs(z[i][j],f+a[i][j]+a[i][k],e);
					
					}
				}
				p[step]=0;
			}
		}
		
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out ","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>s[i];
	}
	int k;
	for(int i=1;i<=n;i++){
		cin>>az[i];
		for(int j=1;j<=az[i];j++){
			cin>>z[i][j]>>a[i][j];//cout<<a[i][z[i][j]]<<" ";
			//=l;
		}
	}	
	int w,e;
	for(int i=1;i<=q;i++){
		cin>>w>>e;
		dfs(w,s[w]+s[e],e);
		cout<<ans<<endl;
		ans=99999999;
	
		//
	}
	return 0;
} 
