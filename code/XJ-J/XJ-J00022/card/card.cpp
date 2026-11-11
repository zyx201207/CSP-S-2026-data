#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int a[300002]={0},b[300002]={0};
	cin>>n>>m;
	bool v[300002]={0};
	stack<int> q;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(v[a[j]]){
				while(!(q.top()==a[j])){
					v[q.top()]=0;
					q.pop();
				}
			}
			else{
				q.push(a[j]);
				v[a[j]]=1;
			}
		}
		while(!q.empty()){
			b[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}
