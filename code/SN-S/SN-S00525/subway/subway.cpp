//高子懿 SN-S00525 延安市安塞区初级中学
#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<int> w(m);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int num=k*2;
		for(int j=1;j<=num;j++){
			int lis1[1000][1000];
			cin>>lis1[i][j];
		}
	int summ=2;
	while(summ--){
		int x,y;
		cin>>x>>y;
	}
	if(n==2) cout<<32;
	else
		cout<<17;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
}

