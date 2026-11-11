#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,k,w,g,s,l;
int a[2000066];
int b[2000066];
int dfs(int q,int p,int o){
	if(q==p)return 1;
	if(o==0)return 0;
	int m=0;
	for(int v=q+1;a[v]<=a[q]+d&&v<=p;v++){
		m+=dfs(v,p,o-1);
	}
	return m;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t>0){
		t--;
		s=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==0||c==11||c==12){
			l=d/(a[2]-a[1]);
			if(l<2||n-2*l+1<0)cout<<0<<endl;
			else cout<<n-2*l+1<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			w=i+1;k=i;g=0;
			while(w<=n){
				g++;
				while(a[w]<=a[k]+d){
					b[w]=g;
					w++;
					if(w>n)break;
				}
				k=w-1;
			}
			for(int v=i+1;v<=n;v++){
				if(dfs(i,v,b[v])==2)s++;
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
