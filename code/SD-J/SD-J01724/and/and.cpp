#include<bits/stdc++.h>
#define st string
#define qw long long
using namespace std; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	qw n,m,x=0;
	cin>>n>>m;
	qw a[n+1],b[n+2][31],q=536870912*2,w=30,c[n+1],d=1;
	for(qw i=1;i<=n;i++){
		cin>>a[i];
		q=536870912*2,w=30;
		while(a[i]){
			if(a[i]>=q){
				a-=q;
				b[i][w]++;
				b[n+1][w]++;
			}w--;
			q/=2;
		}
	}for(qw i=0;i<=30;i++){
		b[n+1][i]-=m;
	}qw t;
	for(qw i=30;i>=0;i++){
		if(b[n+1][i]>=0){
			t=i;
			break;
		}
	}for(qw i=1;i<=n;i++){
		if(b[i][t]==1){
			c[d++]=i;
		}
	}for(int i=1;i<m;i++){
		for(int j=0;j<=30;j++){
			b[i+1][j]=b[i][j]&&b[i+1][j];
		}
	}for(int i=0;i<=30;i++){
		x+=b[c[m]][i]*pow(2,i);
	}cout<<x;
return 0;
}
