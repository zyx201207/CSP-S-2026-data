#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int W[N];
bool vis[M];
int ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a,kk=0;
	queue<int> q;
	for(int i=1;i<=n;i++) {
		cin>>a;
		q.push(a);
	}
	for(int o=1;o<=n;o++){
		for(int i=1;i<=n;i++){
			W[i]=0;
		}
		for(int j=1;j<o;j++){
			q.push(q.front());
			q.pop();
		}
		for(int j=o;j<=n;j++){
			int e=q.front(),p=-1;
			q.push(q.front());
			q.pop();
			for(int i=1;i<=kk;i++){
				if(kk==e){
					p=i;
				}
			}
			for(int i=p+1;i<=kk;i++){
				W[i]=0;	
			}
			kk=kk-p-1;
		}
		for(int j=1;j<=m;j++){
			vis[j]=false;
		} 
		for(int i=1;i<=kk;i++){
			vis[W[i]]=true;
		}
		for(int i=1;i<=m;i++){
			if(vis[i]){
				ans[i]++;
			} 
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	} 
	return 0;
}