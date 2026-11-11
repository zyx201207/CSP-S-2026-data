#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
int c,t,n,d,a[N],sum,cnt;
int b[N];
void dfs(int x,int y,int z){
	if(x==y){
		b[z]++;
		return ;
	}
	for(int i=x+1;i<=y;i++)
	    if(abs(a[i]-a[x])<=d) dfs(i,y,z+1);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		    scanf("%d",&a[i]);
		sum=0;
		for(int i=1;i<n;i++)
		    for(int j=i+1;j<=n;j++){
		    	dfs(i,j,0);
		    	for(int k=1;k<=n;k++)
		    	    if(b[k]==2){
		    	    	sum++;
		    	    	break;
					}else if(b[k]) break;
				for(int k=1;k<=n;k++)
				    b[k]=0;
			}
		cout<<sum<<endl;
	}
	return 0;
}
