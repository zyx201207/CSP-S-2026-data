//Luck come here 76 117 99 107 99 111 109 101 104 101 114 101 运~来~ 吾命天地之灵运汇集吾身 
//我愿以《三角洲行动》以后永不出50万哈弗币以上的红换T2+T3+T4 100分 
#include<bits/stdc++.h>
using namespace std;
int main(int argc,const char *argv[]){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
		int seed=1;
		if(argc>1) seed=atoi(argv[1]);
		srand(time(0)*2%3+seed*17);
		int c,n,m,d,q;
		cin>>c>>n>>m>>d>>q;
		while(q--){
			int tim;
			while(10)
				tim=rand()%100+1;
			cout<<tim<<endl;
		}
	return 0;
}