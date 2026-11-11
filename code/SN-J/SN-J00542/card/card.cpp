#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
queue<int> q1,q2;
int ans[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int m1=m+1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	for(int i=1;i<=n;i++){		
		for(int j=i;j<=n;j++){
			if(q1.empty()){
				q1.push(a[j]);
				continue;
			}
			while(!q1.empty()){
				if(q1.front()==a[j]){
					while(!q1.empty()){
						q1.pop();
					}
					q1.push(a[j]);
					continue;
				}
				q2.push(q1.front());
				q1.pop();
			}
			while(!q2.empty()){
				q1.push(q2.front());
				q2.pop();
			}
		}
		while(!q1.empty()){
			ans[q1.front()]++;
			q1.pop();
		}
		while(!q1.empty())q1.pop();
		while(!q2.empty())q2.pop();
	}
	for(int i=1;i<=m1;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
