#include<bits/stdc++.h>
using namespace std;
queue <int> q;
int n,m,a[500001],b[300001],ans[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int d=0;
			for(int k=1;k<=m;k++){
				if(b[k]==1&&k==a[j]){
					d=1;
					break;
				}
			}
			if(d){
				while(q.size()>=1){
					b[q.front()]--;
					q.pop();
				}
				q.push(a[j]);
			}
			else{
				q.push(a[j]);
				b[a[j]]++;
			}
		}
		for(int k=1;k<=m;k++){
			b[k]=0;
		}
		
		while(q.size()>=1){
			ans[q.front()]++;
			q.pop();
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
//10 3
//2 3 1 2 1 3 2 3 1 2 1
