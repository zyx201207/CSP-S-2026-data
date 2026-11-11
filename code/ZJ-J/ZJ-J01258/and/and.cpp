#include<bits/stdc++.h>
using namespace std;
string b[200005];
bool f[200005];
int n,m,a,ans,e;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		while(a>0){
			b[i]=char(a%2+'0')+b[i];
			a/=2;
		}
		while(b[i].size()<30) b[i]="0"+b[i];
	}
	e=1<<29;
	for(int j=0;j<30;j++){
		int x=0;
		for(int i=1;i<=n;i++){
			if(f[i]) continue;
			if(b[i][j]=='1') x++;
		}
		if(x<m){
			for(int i=1;i<=n;i++){
				if(f[i]) continue;
				b[i][j]='0';
			}
		}
		else{
			ans+=e;
			for(int i=1;i<=n;i++){
				if(b[i][j]=='0') f[i]=true;
			}
		}
		e=e>>1;
	}
	printf("%d",ans);
	return 0;
}