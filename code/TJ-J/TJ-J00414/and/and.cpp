#include<bits/stdc++.h>
using namespace std;
int jg,maxn,jiey;
int n,m;
int a[200026];
void awy(int a,int b){
	int e=1,f=1,ns=0,shu=0;
	char c[15];
	char d[15];
	char g[15];
	for(int i=0;i<15;i++){
		c[i]=' ';
		d[i]=' ';
		g[i]=' ';
	}
	int ershu=2;
	int zr=0;
	while(!(ershu>a&&ershu>b)){
		ershu*=2;
		shu++;
	}
	ershu/=2;
	zr=ershu;
	while(ershu!=0){
		if(a-ershu>=0){
			a-=ershu;
			c[e]='1';
			e++;
		}else{
			c[e]='0';
			e++;
		}
		if(b-ershu>=0){
			b-=ershu;
			d[f]='1';
			f++;
		}else{
			d[f]='0';
			f++;
		}
		ershu/=2;
	}
	for(int i=1;i<=shu+1;i++){
		if(c[i]=='1'&&d[i]=='1'){
			g[i]='1';
		}else{
			g[i]='0';
		}
	}
	for(int i=1;i<=shu+1;i++){
		if(g[i]=='1'){
			ns+=zr;
			zr/=2;
		}else{
			zr/=2;
		}
	}
	jg=ns;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		maxn=max(maxn,a[i]);
	}
	if(m==1){
		cout<<maxn;
	}else if(m==2){
		maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					awy(a[i],a[j]);
				}
				maxn=max(maxn,jg);
			}
		}
		cout<<maxn;
	}else if(m==n){
		maxn=a[1];
		for(int i=2;i<=n;i++){
			awy(maxn,a[i]);
			maxn=jg;
		}
		cout<<maxn;
	}else if(m==(n-1)){
		for(int j=1;j<=n;j++){
			maxn=a[1];
			for(int i=2;i<=n;i++){
				if(i!=j){
					awy(maxn,a[i]);
					maxn=jg;					
				}
			}
		}
		cout<<maxn;
	}
	return 0;
}
