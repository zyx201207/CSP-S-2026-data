#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=2e5+5;//log2(N)=18
LL in(){
	LL aa=0,bb=1;
	char cc=getchar();
	while(cc<'0'||cc>'9'){
		if(cc=='-')	bb=-1;
		cc=getchar();
	}
	while(cc>='0'&&cc<='9'){
		aa=(aa<<3)+(aa<<1)+(cc^48);
		cc=getchar();
	}
	return aa*bb;
}
void out(LL aa){
	if(aa<0){
		aa=-aa;
		putchar('-');
	}
	if(aa<=9)	putchar(aa+'0');
	else{
		out(aa/10);
		putchar(aa%10+'0');
	}
	return ;
}
LL pos[N][20],x[N];
bool is(LL u,LL v,LL d){
	LL len=0,p=u;
	if(v-u<=2)	return 0;
	for(int j=18;j>=0;j--){
		if(pos[p][j]<v){
			p=pos[p][j];
			len+=(1LL<<j);
		}
	}
	len++;
	if(len==1)	return 0;
	LL lst1=u,lst2=u,len1=len-1,len2=len-2;
	for(int j=18;j>=0;j--){
		if(len1>=(1LL<<j))	lst1=pos[lst1][j],len1-=(1LL<<j);
	}
	for(int j=18;j>=0;j--){
		if(len2>=(1LL<<j))	lst2=pos[lst2][j],len2-=(1LL<<j);
	}
	if(lst1-lst2==2 && x[v]-x[lst1-1]<=d)	return 1;
	return 0;
}
void solve(){
	LL n=in(),d=in(),ans=0;
	//³õÊ¼»¯
	for(int i=1;i<=n;i++){
		for(int j=0;j<=18;j++)	pos[i][j]=0;
	}
	int r=2; 
	for(int i=1;i<=n;i++)	x[i]=in();
	
	for(int i=1;i<=n;i++){
		while(r<=n && x[r]-x[i]<=d)	r++;
		r--;
		pos[i][0]=r;
	}
	//for(int i=1;i<=n;i++)	printf("%lld ",pos[i][0]);printf("\n");
	for(int j=1;j<=18;j++){
		for(int i=1;i<=n;i++){
			pos[i][j]=pos[ pos[i][j-1] ][ j-1 ];
		}
	}
	for(int u=1;u<=n-1;u++){
		for(int v=u+1;v<=n;v++){
			if(is(u,v,d)){
				//printf("(%d %d)",u,v);
				ans++;
			}
		}
	}
	out(ans);
	putchar('\n');
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	LL c=in(),T=in();
	while(T--)	solve();
	return 0;
}
/*
0 1
5 3
-2 -1 0 1 2

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
