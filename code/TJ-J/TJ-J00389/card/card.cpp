#include<bits/stdc++.h>
using namespace std;
int a[500007],p[300007],ans[300007];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int f1=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>a[i-1])f1=1;
	}	
	if(!f1){
		for(int i=1;i<=m;i++)cout<<n<<' ';
	}
	for(int i=1;i<=n;i++){
		memset(p,-1,sizeof(p));
		for(int j=i;j<=n;j++){
			if(p[a[j]]==-1)p[a[j]]=j;
			else{
				for(int k=p[a[j]]+1;k<=j;k++){
					p[a[k]]=-1;
				}
				p[a[j]]=j;
			}
		}
		for(int j=1;j<=m;j++){
			if(~p[j])ans[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}

