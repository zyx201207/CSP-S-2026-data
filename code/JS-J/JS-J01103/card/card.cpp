#include<bits/stdc++.h>
using namespace std;

int n,m,a[500010],cnt[300010];
bool b[300010];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		stack<int> s;
		for(int j=i;j<=n;j++){
			if(b[a[j]]){
				while(s.top()!=a[j]){
					b[s.top()]=0;
					s.pop();
				}
			}else{
				s.push(a[j]);
				b[a[j]]=1;
			}
		}
		while(!s.empty()){
			cnt[s.top()]++;
			b[s.top()]=0;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",cnt[i]);
	}
}