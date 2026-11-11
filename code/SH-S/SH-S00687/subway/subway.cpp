#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int c,n,m,d,p;
int w[N];
vector<pair<int,int>> a[N]; 
void s_a(){
	while(p--){
	
		int x,y;
		cin>>x>>y;
		bool flag=0;
		for (auto v1 : a[x]){
			for (auto v2 : a[y]){
				if (v1.first==v2.first){
					cout<<w[x]+w[y]+v2.second+v1.second<<'\n';
					flag = 1;
					
					break;
				}
			}
			if (flag) break;
			
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin.tie(0);
	cin>>c>>n>>m>>d>>p;
	for (int i = 1; i <= m; i++)
	cin>>w[i];
	for (int i = 1; i <= n; i++){
		int k;
		cin>>k;
		for (int j = 1; j <= k; j++){
			int a1,t1;
			cin>>a1>>t1;
			a[a1].push_back({i,t1});
		}
	}
	s_a();
	return 0;
}







