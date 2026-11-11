#include<bits/stdc++.h>
using namespace std;
//priority_queue<int>
#define mian main
#define ll long long
int n,d;
bool vis1[200005],vis3[200005];
int x[200005],ans,vis2[200005],min1[200005],num[200005];
void dfs(int pos,int num){
	if(pos > n)return;
	for (int i = 1;i <= d;i ++){
		if(vis1[pos + d] == 1){
			dfs(pos + d,num ++);
		}
	}
	return;
}
int mian(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);    cin.tie(0);
	int T,c;
	cin >> c >> T;
	while(T--){
		cin >> n >> d;
		for (int i = 0;i < n;i ++){
			cin >> x[i];
			vis1[x[i]] = 1;
		}
		for (int i = 0;i < n;i ++){
			queue<int> jj;
			jj.push(x[i]);
			while(jj.size()){
				for (int i = 1;i <= d;i ++){
					int pos = jj.front();jj.pop();
					if(vis1[pos] == 1){
						min1[pos + d] = vis2[pos] + 1;
						vis1[pos]
					}
						
					}
				}
			}
			
			cout <<ans <<'\n';	
			ans = 0;		
		}
		
	}
	return 0;
}

