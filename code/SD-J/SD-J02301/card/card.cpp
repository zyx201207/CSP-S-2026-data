#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],cnt=0,zt[300005],o=0,p=0;
bool t[300005];
stack<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) o++;
		if(a[i]==2) p++;
		if(a[i]!=b[cnt]){
			b[++cnt]=a[i];
		}
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(t[a[j]]){
				while(q.top()!=a[j]){
					t[q.top()]=false;
					q.pop(); 
				}
			}
			else{
				q.push(a[j]);
				t[a[j]]=true;
			}
		}
		for(int j=1;j<=m;j++){
			if(t[j]) zt[j]++;
			t[j]=false;
		}
		while(!q.empty()){
			q.pop();
		}
	}
	for(int i=1;i<m;i++){
		printf("%d%c",zt[i],' ');
	}
	printf("%d",zt[m]);
	return 0;
}
