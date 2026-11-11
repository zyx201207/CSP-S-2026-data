#include<bits/stdc++.h>
using namespace std;

int n,m,a[500005],k[300005],ans[300005];
stack<int> p;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(k[a[j]]){
				while(true){
					int tmp=p.top();
					k[tmp]--;
					p.pop();
					if(!k[a[j]])
						break;
				}
			}
			k[a[j]]++;
			p.push(a[j]);
		}
		while(!p.empty()){
			ans[p.top()]++;
			k[p.top()]--;
			p.pop();
		}
	}
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
	return 0;
}