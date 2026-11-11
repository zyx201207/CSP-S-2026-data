#include<bits/stdc++.h>
using namespace std;
using PII=pair<int,int>;
using ll=long long;
int c,n,m,d,k;
int w[500010];
int T;
vector<int>a[500];
//greater<>;
//vector<>a;
//stack<>;
//queue q;
void dfs(int x,int y){

}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>T;
	for(int i=1;i<=m;i++){
        cin>>w[i];
	}
	cin>>k;
	for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            int l,t;
            cin>>l>>t;
            a[l].push_back(t);
        }
	}
	while(T--){
        int x,y;
        cin>>x>>y;
        dfs(x,y);
	}
return 0;
}
