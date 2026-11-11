#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
struct node{
	int to;
	int length;
};
vector<node> map[305];
int visit[305];
int n,c,t,d;
int x[305];
int len[305];
int ans;
void minl(long long start,long long end){
	queue<long long> q;
	q.push(start);
	while(!q.empty()){
		long long t=q.front();
		q.pop();
		for(long long i=0;i<map[t].size();i++){
			if(len[t]+map[t][i].length==len[map[t][i].to]&&i==end){
				ans++;
			}
			if(len[t]+map[t][i].length<len[map[t][i].to]){
				q.push(map[t][i].to);
				len[map[t][i].to]=len[t]+map[t][i].length;
			}
		}
	}
	return ;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<305;i++){
			map[i].clear();
			visit[i]=0;
			len[i]=INT_MAX;
			
		}
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;x[j]-x[i]<=d&&j<=n;j++){
				map[i].push_back({j,x[j]-x[i]});
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				minl(i,j);
			}
		}
		cout<<ans<<endl;
	}
    return 0; 
}

