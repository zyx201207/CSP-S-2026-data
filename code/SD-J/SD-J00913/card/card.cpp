#include<bits/stdc++.h>
using namespace std;
const int N=500001;
int a[N],n,m,t[N];
int ans[N];
bool mk[N];
int card[N],z;
void push(int x){
	z++;
	card[z]=x;
}
void pop(){
	z--;
}
int top(){
	return card[z];
}
bool empty(){
	return z==0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		memset(t,0,sizeof(t));
		for(int j=i;j<=n;j++){
			push(a[j]);
			t[a[j]]++;
			if(t[a[j]]>1){
				do{
					int u=top();
					t[u]--;
					pop();
				}
				while(top()!=a[j]);
			}
		}
		memset(mk,false,sizeof(mk));
		while(!empty()){
			int u=top();
			if(!mk[u]){
				ans[u]++;
				mk[u]=true;
			}
			pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
