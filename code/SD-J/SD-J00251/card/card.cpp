#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10,M=3e5+10;
int n,m,f,t;
int a[N],ans[M],b[3001];
bool vis[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool fl=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) fl=0;
		if(a[i]!=a[i+1]) f++;
		else b[a[i]]++;
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			stack<int> q;
			for(int j=i;j<=n;j++){
				q.push(a[j]);
				//cout<<vis[a[j]]<<" "<<j<<":"<<endl;
				if(!vis[a[j]]) vis[a[j]]=1;
				else if(vis[a[j]]){
					q.pop();
					while(q.top()!=a[j]&&!q.empty()){
						//cout<<q.top()<<" ";
						vis[q.top()]=0;
						q.pop();
					}
				}
			}
			while(!q.empty()){
				ans[q.top()]++;
				vis[q.top()]=0;
				//cout<<q.top()<<" ";
				q.pop();
			}
			//cout<<endl;
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	}else if(fl){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]) ans[a[i]]+=i;
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	}else if(f<=4999){
		sort(b+1,b+m+1);
		for(int i=1;i<=n;i++){
			stack<int> q;
			for(int j=i;j<=n;j++){
				if(a[j]==b[m]) break;
				q.push(a[j]);
				//cout<<vis[a[j]]<<" "<<j<<":"<<endl;
				if(!vis[a[j]]) vis[a[j]]=1;
				else if(vis[a[j]]){
					q.pop();
					while(q.top()!=a[j]&&!q.empty()){
						//cout<<q.top()<<" ";
						vis[q.top()]=0;
						q.pop();
					}
				}
			}
			while(!q.empty()){
				ans[q.top()]++;
				vis[q.top()]=0;
				//cout<<q.top()<<" ";
				q.pop();
			}
			//cout<<endl;
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	}else{
		for(int i=1;i<=n;i++){
			stack<int> q;
			for(int j=i;j<=n;j++){
				q.push(a[j]);
				//cout<<vis[a[j]]<<" "<<j<<":"<<endl;
				if(!vis[a[j]]) vis[a[j]]=1;
				else if(vis[a[j]]){
					q.pop();
					while(q.top()!=a[j]&&!q.empty()){
						//cout<<q.top()<<" ";
						vis[q.top()]=0;
						q.pop();
					}
				}
			}
			while(!q.empty()){
				ans[q.top()]++;
				vis[q.top()]=0;
				//cout<<q.top()<<" ";
				q.pop();
			}
			//cout<<endl;
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	} 
	return 0;
}

