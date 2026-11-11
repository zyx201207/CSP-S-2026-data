#include<bits/stdc++.h>
using namespace std;

int n,m,a[510000],c[510000];
bool b[510000];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=m;i++){
			b[i]=false;
		}
		stack<int> q;
		for(int i=k;i<=n;i++){
			if(b[a[i]]==false){
				b[a[i]]=true;
				q.push(a[i]);
			}
			else{
				while(q.top()!=a[i]){
					b[q.top()]=false;
					q.pop();
				}
			}
		}
		while(q.empty()==false){
			++c[q.top()];
			q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",c[i]);
	}
	return 0;
}
