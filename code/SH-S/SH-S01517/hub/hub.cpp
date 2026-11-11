#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000006;
int c,T; 
vector<int> to[N];
void solveTP(int n,int k){
	if(k>=n){
		cout<<0<<endl;
		return;
	}
	if(k>=n/2){
		cout<<1<<endl;
		return;
	}
	int m=n/2;
	m-=k;
	m=(m+7)/4;
	cout<<m<<endl;
	return;
}
void solveBF(int n,int k){
	cout<<"I can't solve it"<<endl;
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	for(int t=1;t<=T;t++){
		int n,k,u,v;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>u>>v;
			to[u].push_back(v);
			to[v].push_back(u);
		}
		if(n%2){
			bool tp=1;
			for(int i=1;i<=n/2;i++){
				if(i==1&&(to[i].size()!=2)){
					tp=0;
					break;
				}
				if(i!=1&&(to[i].size()!=3)){
					tp=0;
					break;
				}
				for(int j=0;j<to[i].size();j++){
					if((to[i][j]!=i+1)&&(to[i][j]!=i+n/2+1)&&(to[i][j]!=i-1)){
						tp=0;
						break;
					}
				}
				if(!tp) break;
			}
			if(tp){
				solveTP(n,k);
				continue;
			}
		}
		solveTP(n,k);
		for(int i=1;i<=n;i++) to[i].clear();
	}
	return 0;
} 
