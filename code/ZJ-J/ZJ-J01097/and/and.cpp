#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,x,t,s,ans,b[200010],c[200010];
bool a[200010][31];
bool cmp(int q,int h){return q>h;} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>c[i];
	sort(c+1,c+n+1,cmp);
	for(i=1;i<=n;i++){
		x=c[i];t=0;
		while(x){
			a[i][30-t]=x%2;
			x/=2;t++;
		}
	}
	for(i=1;i<=30;i++){
		s=0;
		for(j=1;j<=n;j++)
			s+=a[j][i];
		if(s>=m) break;
	}
	if(i>30) cout<<0;
	else{
		t=0;
		for(j=1;j<=n;j++)
			if(a[j][i]){
				b[++t]=c[j];
				if(t>m) break;
			}
		ans=b[1];
		for(i=2;i<=m;i++) ans=ans&b[i]; 
		cout<<ans;
	}
} 
