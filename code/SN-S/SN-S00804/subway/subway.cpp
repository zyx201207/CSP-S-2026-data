#include<fstream>
typedef long ll;
using namespace std;


int m,v[500000],qs[500000][2],q;
int n,a[500][1001],t[500][1000];


int main(){
	ifstream fin("subway.in");
	ofstream fout("subway.out");
	
	int c,d;
	fin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)fin>>v[i];
	for(int i=0;i<n;i++){
		int k;fin>>k;a[i][0]=k;
		for(int j=1;j<=k;j++)fin>>a[i][k];
	}
	for(int i=0;i<q;i++)fin>>qs[i][0]>>qs[i][1];
	
	
	
	
	return 0;
}

