#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+10;
int c,t; 
int n,d; 
int x[N];
vector<int> ve[N],v2[N];
vector<int> v1;
void F(int y,int v,int l){
	if(y==v){
		v1.push_back(l);
		return;
	}
	for(auto c:ve[y]){
		F(c,v,l+1);
	}
}
void F1(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]<=d){
				ve[i].push_back(j);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+3;j<=n;j++){
			v1.clear();
			F(i,j,0);
			int cnt=0,y=1e9+10;
			for(auto c:v1){
				if(c<y){
					cnt=1;
					y=c;
				} else if(c==y) cnt++;
			}
			if(cnt==2){
				ans++;
//				cout<<i<<' '<<j<<endl;
			}
		}
	}
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++) ve[i].clear();
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(c<=2) F1();
	}
	return 0;
} 
