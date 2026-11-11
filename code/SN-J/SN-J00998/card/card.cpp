#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int vis[300005];
int f[300005];
deque<int> w;
queue<int> q;
int sum,o;
int fun(int j){
	int p=0;
	while(!w.empty()){
		o=w.front();
		if(o==a[j]){
			p=1;
		}
		q.push(o);
		w.pop_front();
	}
	while(!q.empty()){
		sum=q.front();
		w.push_back(sum);
		q.pop();
	}
	return p;
}
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[a[i]]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int p=0,fac=0;
			while(!w.empty()){
				o=w.front();
				if(o==a[j]){
					p=1;
					fac=j;
				}
				w.pop_front();
				q.push(o);
			}
			while(!q.empty()){
				sum=q.front();
				w.push_back(sum);
				q.pop();
			}
			if(w.empty()){
				w.push_back(a[j]);
			}else if(p==1){
				while(fun(j)==1){
					w.pop_back();
				}
			}else{
				w.push_back(a[j]);
			}
			while(!w.empty()){
				o=w.front();
				vis[o]++;
				q.push(o);
				w.pop_front();
			}
			while(!q.empty()){
				sum=q.front();
				w.push_back(sum);
				q.pop();
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<vis[i]<<" ";
	}
	return 0;
}
