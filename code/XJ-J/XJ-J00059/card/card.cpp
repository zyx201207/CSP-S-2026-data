#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];

int t[300005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(t,0,sizeof(t));
		queue<int>q;
		for(int j=i;j<=n;j++){
			if(!t[a[j]]){
				q.push(a[j]);
				t[a[j]]=1;
			}
			else if(t[a[j]]&&j!=n){
				while(q.size()){
					t[q.front()]=0;
					q.pop();
				}
				q.push(a[j]);
				t[a[j]]=1;
			}
		}
		for(int k=1;k<=m;k++){
			if(t[k]){
				ans[k]++;
				//cout<<k<<" ";
			}
		}
		//cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" "; 
	}
	return 0;
} 
