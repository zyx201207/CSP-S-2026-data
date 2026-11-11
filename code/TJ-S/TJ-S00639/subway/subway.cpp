#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d[1000000],d2[1000000],e,r,t,p[1000000],p2[1000][1000],p3[1000][1000],s,q,k[1000][1000],k2[1000];
int bf(int x,int y){
	for(int i=1;i<p[x];i++){
		if(p2[x][i]==y) return i;
	}
	return 0;
}
int df(int x,int y,int z,int h){
	int o=999999999,w=0;
 	for(int i=1;i<=k2[x];i++){
 		if(i==z) continue;
 		for(int j=1;j<=p[k[x][i]];j++){
 			if(p2[k[x][i]][j]==y){
 				if(o>p3[k[x][i]][j]+p3[k[x][i]][bf(k[x][i],x)]+h){
				 	o=p3[k[x][i]][j]+p3[k[x][i]][bf(k[x][i],x)]+h;
				 	w=1;
				 	break;
				 }
			 }
		 }
		 if(w==0){
 			for(int j=1;j<=p[k[x][i]];j++){
 				int n=df(p2[k[x][i]][j],y,k[x][i],h+p3[k[x][i]][j]+p3[k[x][i]][bf(k[x][i],x)]);
 				if(n<o) o=n;
		 	}
		 }
		 w=0;
	 }
	return o;
 }
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>a;
	while(a--){
		cin>>b>>c>>r>>t;
		for(int i=1;i<=c;i++) cin>>d[i];
		for(int i=1;i<=b;i++){
			cin>>p[i];
			for(int j=1;j<=p[i];j++){
				cin>>p2[i][j]>>p3[i][j];
				k[p2[i][j]][k2[p2[i][j]]]=j;
				k2[p2[i][j]]++;
			}
		}
	}
	for(int i=0;i<t;i++){
		cin>>s>>q;
		e+=d[s]+d[q];
		cout<<e+df(s,q,0,0)<<endl;
	}
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2

