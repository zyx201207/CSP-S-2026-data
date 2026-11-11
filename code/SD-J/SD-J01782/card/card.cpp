 
 #include <bits/stdc++.h>
using namespace std;
int n,m;
int c[501010];
int v[301010];
int a[301010];
stack<int> q;
int main() {
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int k=1;k<=n;k++){
	for(int i=k;i<=n;i++){
			if(v[c[i]]==1){
				while(!q.empty()) q.pop();
				memset(v,0,sizeof(v));
			}
			int y=c[i];
			q.push(y);
			v[y]=1;
		}
		for(int ii=1;ii<=m;ii++){
			if(v[ii]==1) a[ii]++;
		}
		while(!q.empty()) q.pop();
		memset(v,0,sizeof(v));
	}
		
	for(int i=1;i<=m;i++){
		cout<<a[i]<<' ';
	}
	return 0;
}
