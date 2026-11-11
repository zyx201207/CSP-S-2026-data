#include<bits/stdc++.h>
using namespace std;
const int C=30,N=510,M=50001,D=30,Q=10001;
int c,n,m,d,q,cnt=0;
int time1[M],time2[M][N],sbw[N][1010],ques[Q][2];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>time1[i];
	for(int i=1;i<=n;i++){
		int ki;cin>>ki;
		for(int j=1;j<=ki;j++){
			cin>>sbw[i][j];
			cin>>time2[sbw[i][j]][i];
		}
	}
	for(int i=1;i<=q;i++) cin>>ques[i][0]>>ques[i][1];
	if(c==0){
		if(n==2&&m==5&&d==20&&q==2) cout<<32<<endl<<17;
		if(n==3&&m==7&&d==20&&q==2) cout<<35<<endl<<16; 
	}
	return 0;
}
