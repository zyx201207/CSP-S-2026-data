#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,j,k,l,x,t,z,s,d,g,h,q,a[200100],ma,b[200100],f[50],e[200100][35],u[35],r;
bool bb(){
	int i,j,o=0;
	for(j=0;j<=r;j++)
		if(b[j]==1){
			for(i=1;i<=n;i++)
				if(e[i][j]==1)
					o++;
			if(o<m) return 0;
			o=0;
		}
	return 1;
}
void aa(int t,int g){
	if(g+f[t]<d) return ;
	if(t==-1){
		if(bb()) d=max(d,g);
		return ;
	}
	b[t]=1;aa(t-1,g+f[t]);
	b[t]=0;aa(t-1,g);
}
void cc(int t,int o){
	int i;
	if(o>n) return ;
	if(t==m+1){
		int g=b[1];
		for(i=2;i<=m;i++) g=(g&b[i]);
		d=max(d,g); 
		return ;
	}
	for(i=o+1;i<=n;i++)
		b[t]=a[i],cc(t+1,i);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;f[0]=1;
	for(i=1;i<=30;i++) f[i]=f[i-1]*2;
	for(i=1;i<=n;i++){
		cin>>a[i];x=a[i],q=max(ma,a[i]);
		for(j=30;j>=0;j--)	if(x>=f[j])	x-=f[j],e[i][j]=1;
	}
	if(m==1) cout<<q,exit(0);
	else if(m==n){
		for(j=0;j<=30;j++){
			for(i=1;i<=n;i++) if(e[i][j]==0) break;
			if(i>n) d+=f[j];
		}
	}
	else if(m==2&&n<10000){for(i=1;i<=n;i++) for(j=i+1;j<=n;j++) d=max(d,a[i]&a[j]);}
	else if(m==n-1){
		for(j=0;j<=30;j++) for(i=1;i<=n;i++) u[j]+=e[i][j];
		for(i=1;i<=n;i++){
			g=0;
			for(j=0;j<=30;j++) if(u[j]-e[i][j]==n-1) g+=f[j];
			d=max(d,g);
		}
	}
	else if(n<=20){cc(1,0);}
	else{
		for(j=0;j<=30;j++) if(q>f[j]&&q<=f[j+1]){r=j+1;break;}
		if(q==1) r=1;
		aa(r,0);
	}
	cout<<d;
	return 0;
}