#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],cf[200010],s[200010];
stack<long long> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}//n数量 m种类 
	for(long long t=1;t<=n;t++){
		for(long long i=t;i<=n;i++){//一次游戏 
			if(s[a[i]]==0){
				q.push(a[i]);
				s[a[i]]++;
			}else{
				while(q.top()!=a[i]){
					s[q.top()]--;
					q.pop();
				}
			}
		}
		while(!q.empty()){
			cf[q.top()]+=1;
			q.pop();
		}
		for(long long i=1;i<=m;i++){
			s[i]=0;
		}
	}
	for(long long i=1;i<=m;i++){
		printf("%lld ",cf[i]);
	}
	return 0;
}
