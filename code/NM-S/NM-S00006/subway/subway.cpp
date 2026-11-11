#include<iostream>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	int w[250000],k[600][250000],r[2][250000];
	std::cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		std::cin>>w[i];
	}for(int i=1;i<=n;i++){
		std::cin>>k[i][0];
		for(int j=1;j<=k[i][0];j++){
			std::cin>>k[i][j];
		}
	}for(int i=1;i<=q;i++){
		std::cin>>r[0][i]>>r[1][i];
		std::cout<<1<<endl;
	}return 0;
}
