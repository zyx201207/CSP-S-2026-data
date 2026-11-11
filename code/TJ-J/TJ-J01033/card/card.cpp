#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005];
stack<int> q,p;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
		for(int i = 1;i <= n;i++){
			for(int j = i;j <= n;j++){
				if(!q.empty()){
					while(a[j] != q.top() && !q.empty()){
						p.push(q.top());
						q.pop();
					}
					if(q.empty()){
					while(!p.empty()){
						q.push(p.top());
						p.pop();
						
					}
					q.push(a[j]); 
				}else{
						while(!p.empty())p.pop();	
					}
				
			}else{
				q.push(a[j]);
			}
		}
		while(!q.empty()){
			b[q.top()]++;
			q.pop();
		}
	}
	for(int i = 1;i <= m;i++){
		cout << b[i] << " ";
	}
	return 0;
}
