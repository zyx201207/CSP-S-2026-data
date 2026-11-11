#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
bool v[300005]={0};//是否已经入栈 
int t[300005]={0};//桶，出现次数 
stack<int>s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		memset(v,0,sizeof(v));
		for(int j=i;j<=n;j++){
			if(v[a[j]]==true){
				for(;!s.empty();){
					v[s.top()]=false;
					if(s.top()!=a[j]) s.pop();
					else{
						s.pop();
						break;
					}
				}
			}
			s.push(a[j]);
			if(v[a[j]]==false) v[a[j]]=true;
		}
		for(;!s.empty();){
			int x=s.top();
			t[x]++;
			s.pop();
		}
	}
	
	for(int i=1;i<=m;i++){
		printf("%d ",t[i]);
	}
	
	return 0;
}
