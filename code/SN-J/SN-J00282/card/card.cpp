#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000005];
bool b[1000005];
long long ans[1000005],e[1000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);		
	}

	for(int i=1;i<=n;i++){
		stack<int> q;
		memset(b,false,sizeof b);
		memset(e,0,sizeof e);
		for(int j=i;j<=n;j++){
			if(b[a[j]]==false){
				q.push(a[j]);
				e[a[j]]++;
				b[a[j]]=true;				
			}
			else{
				while(!q.empty()){
					int c=q.top();
					q.pop();
					e[c]--;
					if(e[c]==0){
						b[c]=false;
					}
					if(c==a[j]){
						b[a[j]]=0;
						break;
					}
				}
				q.push(a[j]);
			}
		}
		while(!q.empty()){
			int c=q.top();
			ans[c]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",ans[i]);
	}
	return 0;
}
