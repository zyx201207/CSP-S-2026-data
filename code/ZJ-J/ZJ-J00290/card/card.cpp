#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],v[500005];
int ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	for(int i=1;i<=n;i++){
		stack<int>q;
		memset(v,0,sizeof v);
		for(int j=i;j<=n;j++){
			if(v[a[j]]!=0){
				while(!q.empty()&&q.top()!=a[j]){
					v[q.top()]--;
					q.pop();
				}
			}else{
				q.push(a[j]);
				v[a[j]]++;	
			}
		}
		while(!q.empty()){
			ans[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
