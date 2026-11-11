#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],v[300005];
long long ans[300005];
struct node{
	int num,time;
};
void special(){
	stack<node> st;
	for(int i=n;i>0;i--){
		if(v[a[i]]==0){
			v[a[i]]=1;
			st.push((node){a[i],i});
		}else{
			while(st.top().num!=a[i]){
				node t=st.top();
				v[t.num]=0;
				st.pop();
				ans[t.num]+=(t.time-i);
			}
		}
	}while(st.size()){
		node t=st.top();
		st.pop();
		ans[t.num]+=t.time;
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",ans[i]);
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	if(n>10000){
		special();
		return 0;
	}
	for(int i=1;i<=n;i++){
		stack<node> st;
		memset(v,0,sizeof(v));
		for(int j=i;j<=n;j++){
			if(v[a[j]]==0){
				v[a[j]]=1;
				st.push((node){a[j],j});
			}else{
				while(st.top().num!=a[j]){
					node t=st.top();
					v[t.num]=0;
					st.pop();
				}
			}
		}while(st.size()){
			node t=st.top();
			v[t.num]=0;
			st.pop();
			ans[t.num]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",ans[i]);
	}
	return 0;
}
