#include<bits/stdc++.h>
using namespace std;
int c,T,n,m,x,y;
vector<int> v[500005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<n;i++){
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		int maxn=0,s=0;
		for(int i=0;i<500005;i++){
			s=0;
			for(int j=0;j<v[i].size();j++){
				if(v[i][j]){
					s++;
				}
			}
			maxn=max(maxn,s);
		}
		cout<<maxn<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
