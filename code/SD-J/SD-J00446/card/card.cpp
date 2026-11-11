#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[300005];
int c[300005];
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		for(int aaa=1;aaa<=m;aaa++)b[aaa]=0;
		for(int j=i;j<=n;j++){
			b[a[j]]++;
			if(b[a[j]]>1){
				while(s.top()!=a[j])b[s.top()]--,s.pop();
				s.pop();
			}
			b[a[j]]=1;
			s.push(a[j]);
		}
		while(!s.empty()){
			c[s.top()]++;
			s.pop(); 
		}
	}
	for(int i=1;i<=m;i++)printf("%d ",c[i]);
	return 0;
}
