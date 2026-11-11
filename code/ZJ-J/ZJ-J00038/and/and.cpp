#include<bits/stdc++.h>
using namespace std;
int n,m;
bool a[200010][50];
int d[200010];
bool b[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	    scanf("%d",&d[i]);
	sort(d+1,d+n+1);
	for(int i=1;i<=n/2;i++)
	    swap(d[i],d[n-i+1]);
	for(int i=1;i<=n;i++){
		int x=30,y=d[i];
		while(y>0){
			a[i][x]=y%2;
			y/=2;
			x--;
		}
	}
	for(int i=1;i<=30;i++){
		int x=0;
		for(int j=1;j<=n;j++)
		    if(b[j]==false)
		    	x+=a[j][i];
		if(x<m)
		    continue;
		for(int j=1;j<=n;j++)
		    if(a[j][i]==0)
		    	b[j]=true;
	}
	int x=0,ans=-1;
	for(int i=1;i<=n&&x<m;i++)
		if(b[i]==false){
			if(ans==-1)
		        ans=d[i],x++;
		    else
		        ans&=d[i],x++;
		} 
	printf("%d",ans);
	return 0;
}
