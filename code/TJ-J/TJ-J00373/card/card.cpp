#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
bool d[300005];
int ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	queue<int>q;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(d[a[j]]==0){
				q.push(a[j]);
				d[a[j]]=1;
			}else{
				while(!q.empty()){
					d[q.front()]=0;
					q.pop(); 
				}
//				cout<<a[j];
				q.push(a[j]);
				d[a[j]]=1;
			}
		}
		while(!q.empty()){
			ans[q.front()]++;
			cout<<q.front()<<" ";
			
			q.pop(); 
		}
		cout<<endl;
		for(int k=1;k<=m;k++)d[k]=0;
	}
//	ans[m]++;
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	
	
	return 0;
}
