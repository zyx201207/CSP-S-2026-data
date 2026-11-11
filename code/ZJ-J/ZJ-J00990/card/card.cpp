#include<bits/stdc++.h>
using namespace std;
stack<int> q;
int a[500050],ans[300005];
bool f[300050];
int main()
{
 	freopen("card.in","r",stdin);
 	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)	scanf("%d",&a[i]);
	for(int ii=1;ii<=n;ii++){
		for(int i=1;i<=m;i++)	f[i]=false;
		for(int i=ii;i<=n;i++){
			if(f[a[i]]==true){
				while(q.top()!=a[i]){
					q.pop();
				}
				q.pop();
			}
//			cout<<"***"<<endl;
			f[a[i]]=true;
			q.push(a[i]);
		}
		while(!q.empty()){
			ans[q.top()]++;
			q.pop();
		}
//		cout<<q.size();
	}
	for(int i=1;i<=m;i++)	cout<<ans[i]<<' ';
 	return 0;
}
