#include<bits/stdc++.h>
using namespace std;
int n,m,b[500005],e[500005],ans[500005];
bool a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int c;
		cin>>c;
	    e[i]=c;
	}
	
	
	for(int w=1;w<=n;w++){
		for(int i=1,cn=w;i<=n;i++,cn++){
			if(a[e[cn]]){
				while(b[i]==e[cn]){
					i--;
					a[b[i]]=0;
					//n--;
				}
			}else {
				a[e[cn]]=1;
				b[i]=e[cn];
			}
		}
		for(int i=1;i<=m;i++){
			if(a[i])ans[i]++;
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
