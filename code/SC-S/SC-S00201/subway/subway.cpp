#include<bits/stdc++.h>
using namespace std;
struct o{
	int a,t;
};
int c,n,m,d,q;
vector<int> p[500005];
int w[500005];
vector<o> k[502];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	} 
	for(int i=1;i<=n;i+=1){
		int ki;
		cin>>ki;
		for(int j=1;j<=ki;j+=1){
			int a1,t1;
			
			k[i].push_back({a1,t1});
		}
		for(int j=1;j<ki;j+=1){
			for(int q=i+1;q<=ki;q++){
				p[k[i][j].a].push_back(k[i][q].a);
				p[k[i][q].a].push_back(k[i][j].a);
			}
		}
	}
	for(int i=1;i<=q;i+=1){
		int x,y;
		cin>>x>>y;
		long long num=w[x]+w[y];
		long long sum1,sum2; 
		for(int i1=1;i1<=n;i1++){
			bool o1=0,o2=0;
			for(int j=0;j<k[i].size();j++){
				if(k[i][j].a==x){
					o1=1;
					sum1=k[i][j].t;
				}
				if(k[i][j].a==y){
					o2=1;
					sum2=k[i][j].t;
				}
			}
			if(o1 && o2){
				cout<<num+sum1+sum2;
				return 0;
			}
		} 
	}
	return 0;
}
