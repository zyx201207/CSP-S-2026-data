#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
stack<int>s;
int ans[300010];
bool v[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++){
		ans[i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(v[a[j]]==0){
				s.push(a[j]);
				v[a[j]]=1;
			}else{
				while(s.top()!=a[j]){
					v[s.top()]=0;
					s.pop();
				}
			}
		}
		while(!s.empty()){
			ans[s.top()]++;
			v[s.top()]=0;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
