#include<bits/stdc++.h>
using namespace std;
int n,g;
int a[5005];
int m[300005];
int f[300005];
queue<int>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>g;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			q.push(a[i]);
			m[a[i]]++;
		}
		while(q.empty()==0){
			if(m[q.front()]>1){
				int h=q.front();
				q.pop();
				m[h]--;
				while(q.empty()==0&&q.front()!=h){
					m[q.front()]--;
					q.pop();
				}
			}
			if(m[q.front()]==1){
				q.pop();
			}
		}
		for(int i=1;i<=g;++i){
			f[i]=m[i];
			m[i]=0;
		}
	}
	for(int i=1;i<=g;++i){
		cout<<f[i]<<' ';
	}
	return 0;
}
