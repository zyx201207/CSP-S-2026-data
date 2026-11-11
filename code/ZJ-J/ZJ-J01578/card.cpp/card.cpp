#include<bits/stdc++.h>
using namespace std;
int g[500009];
int n,m,k=1,q=1;
int st[300009],s[300009],s1[300009],ans[300009];
void eat(int s,int x,int j){//start value end
	int t=0;
	for(int i=s;i<=n;i++){
		if(g[i]==x){
			t=i;
		}
	}
	for(int i=t;i<=j-1;i++) s1[g[i]]--;
}
int main(){	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>g[i],s[g[i]]++;
	for(int i=1;i<=n;i++){//n ju
		for(int i=1;i<=m;i++){//memset
			s1[i]=s[i];
		}
		for(int j=k;j<=n;j++){		
			if(st[g[j]]>1)//chong fu
				eat(q,g[j],j),q=j;
			st[g[j]]++;
		}
		for(int i=1;i<=m;i++){
			ans[i]+=s1[i];
		}
		k++;
	}	
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;	
}
