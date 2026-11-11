#include<bits/stdc++.h>
using namespace std;
struct rr{
	int a,t;
};
int c,n,m,d,q;
int w[600];
vector<rr> v[30000];
bool vis[30000];
long long mi=0;
void dfs(int b,int e,long long t){
    //cout<<b<<' '<<t<<';';
	if(b==e){
		if(mi==0){
			mi=t;
		}else{
			mi=min(mi,t);
		}
		//cout<<endl;
		return ;
	}
	for(int i=0;i<v[b].size();i++){
		int nb=v[b][i].a;
		if(vis[nb]==0){
			vis[nb]=1;
			dfs(nb,e,t+v[b][i].t);
			vis[nb]=0;
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	//cout<<c<<' '<<n<<' '<<m<<' '<<d<<' '<<q<<' '<<endl;

	for(int i=1;i<=m;i++){
		cin>>w[i];
		//cout<<w[i]<<' ';
	}
	int k;
	if(c>=7&&c<=11){
        for(int i=1;i<=n;i++){
            cin>>k;
            int a,t;
            if(k==1){
                cin>>a>>t;
            }
            else if(k==2){
                int a1,t1,a2,t2;
                cin>>a1>>t1>>a2>>t2;
                v[a1].push_back({a2,t1+t2});
                v[a2].push_back({a1,t1+t2});
            }
        }
	}else{
        for(int i=1;i<=n;i++){
            cin>>k;
            //cout<<k<<' ';
            for(int j=1;j<=k;j++){
                int a,t;
                cin>>a>>t;
                //cout<<a<<' '<<t<<' ';
                v[m+i].push_back({a,t});
                v[a].push_back({m+i,t});
            }
            //cout<<endl;
        }
	}
	for(int i=1;i<=q;i++){
		int r,l;
		cin>>r>>l;
		//cout<<r<<' '<<l<<endl;
		mi=0;
		vis[r]=1;
		dfs(r,l,0);
		vis[r]=0;
		cout<<mi+w[r]+w[l]<<endl;
	}
return 0;
}
