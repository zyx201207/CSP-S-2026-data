#include <bits/stdc++.h>
using namespace std;
const int N1=2e6+10;
int c,t,n,d,x[N1];
//pair<bool,long long> x[N];
//pair<bool,long long> add(pair<bool,long long> a,pair<bool,long long>){
//	if (a.first^b.first==0) return {a,first,a.second+b.second};
//	else{
//		if (a.second==b.second) return {0,0};
//		else if (a.second>b.second) return {a.first,a.second-b.second};
//		else return {b.first,b.second-a.second};
//	}
//}
struct node{
	int i,len,num;
};
struct node1{
	int len,num;
};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		int cnt=0;
		cin >> n >> d;
		vector<int> v[N1];
		for (int i=1,j=1;i<=n;i++){
			cin >> x[i];
			while(j<i){
				if (abs(x[i]-x[j])>d) j++;
				else{
					for (int k=j;k<i;k++) v[k].push_back(i);
					break;
				}
			}
		}
//		for (int i=1;i<=n;i++){
//			cout << i << ":";
//			for (int j=0;j<v[i].size();j++){
//				cout << v[i][j] << " ";
//			}
//			cout << endl;
//		}
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				queue<node> q;
				q.push({i,0});
				node1 vis[N1]{};
				vis[i]={0,1};
				while(!q.empty()){
					node t=q.front();
					q.pop();
					for (int l=0;l<v[t.i].size();l++){
						node nt={v[t.i][l],t.len+1,t.num};
						if (vis[nt.i].num==0){
							q.push(nt);
							vis[nt.i].num+=nt.num;
						}
						if (vis[nt.i].len==nt.len){
							vis[nt.i].num+=nt.num;
						}
					}
				}
				if (vis[j].num==2) cnt++;
			}
		}
		cout << cnt << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
