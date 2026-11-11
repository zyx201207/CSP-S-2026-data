#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500002];
int t[300002];int pos[300002];
stack<int> q;
signed main(){
	   freopen("card.in","r",stdin);
	   freopen("card.out","w",stdout);
	   ios::sync_with_stdio(false);
	   cin.tie(0);
	   cout.tie(0);
	   cin >> n >> m;
	   for(int i = 1;i <= n;i ++){
	   		cin >> a[i];
	   	}
	   
	   	for(int i = 1;i <= n;i ++){
	   		for(int j = i;j <= n;j ++){
	   			if(pos[a[j]] == 0){
	   				pos[a[j]] = j;	
	   				q.push(a[j]);
				}
				else{
					for(int k = pos[a[j]];k < j;k ++){
						if(q.size()){
							for(int c = 1;c <= m;c ++){
								if(pos[c] == k){
									pos[c] = 0;
									break;
								}
							}
							q.pop();
						}
						
					}
					q.push(a[j]);
					pos[a[j]] = j;
				}
			}	
			while(!q.empty()){
				t[q.top()] ++;
				q.pop();
			}
			for(int j = 1;j <= m;j ++){
				pos[j] = 0;
			}
		}
		
		for(int i = 1;i <= m;i ++){
			cout << t[i] << ' ';
		}
	   return 0;
 }

