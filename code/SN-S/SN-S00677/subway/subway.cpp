#include<bits/stdc++.h>
using namespace std;
const int K=5e5+7;
int c,n,m,d,q;
long long ans=0;
struct point{
	bool way[507];
	int to_espace,to_stop;
}stop[K];
vector<int> gt[507];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)	cin>>stop[i].to_espace;	
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		while(k--){
			int p;cin>>p;
			cin>>stop[p].to_stop;
			stop[p].way[i]=true;
			gt[i].push_back(p);
		}	
	}
	while(q--){
		ans=0;
		int starts,ends;
		cin>>starts>>ends;
		bool flag=false;
		ans=stop[starts].to_espace+stop[starts].to_stop+stop[ends].to_stop+stop[ends].to_espace;
		for(int i=1;i<=n;i++){
			if(stop[starts].way[i]&&stop[ends].way[i]){
				flag=true;
				cout<<ans<<endl;
				break;
			}
		}
		if(flag){
			flag=false;
			continue;
		}
		
	}
	cout<<ans<<endl;
	return 0;
}
