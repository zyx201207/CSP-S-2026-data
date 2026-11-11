#include<bits/stdc++.h>
using namespace std;
queue<int>q;
int n,m;
int a[500001],b[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(n==m){
		for(int i=1;i<=m;i++) cout<<1<<' ';
		return 0;
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			q.push(a[j]);
			for(int k=i;k<j;k++){
				if(a[j]==a[k]){
					for(int t=1;t<k;t++){
						q.push(q.front());
						q.pop();
					}
					for(int t=k;t<j;t++) q.pop();
					q.push(q.front());
					q.pop();
				}else continue;
			} 
		}
		while(!q.empty()){
			int c[300001]={};
			if(!c[q.front()]){
				b[q.front()]++;
				c[q.front()]=1;
				q.pop();
			}else q.pop();
		} 
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
