#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,end=0;
	cin >>n>>m;
	int num[200010];
	int z[200010][200010];
	for(int i=1;i<=n;i++){
		cin >> num[i];
		z[1][i]=num[i];	
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			for(int p=1;p<=n;p++){
				z[i+1][j]=max(z[i][j]&num[p],z[i][j]);
			}

		}
	}
	for(int i=1;i<=n;i++){
		if(end<z[m][n]){
			end=z[m][n];
			cout << end;
		}
	}
	return 0;
}
