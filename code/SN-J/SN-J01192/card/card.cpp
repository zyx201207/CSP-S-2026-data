#include <bits/stdc++.h>
using namespace std;
//847-900
/*struct s{
	int b[100];
};*/
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("card.in",'r',stdin);
	freopen("card.out",'w',stdout);
	int n,m;
	cin >> n >> m;
	vector<int> a;
	int result[n+5][n]={0};
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		a.push_back(x);
	}
	//struct s result[n+5];
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			if(i==0) result[k][0]=a[0];
			else{
				long long z=a[i];
				size_t f=result[k].find(z);
				if(f==string::npos){
					result[k][i]=a[i];
				}else{
					for(int j=f;j<n;j++)result[k][j]=0;
					result[k][i]=a[i];
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		int times=0;
		for(int j=0;j<n;j++){
			if(result[i][j]==i+1){
				times++;
			}
		}
		cout << times << ' ';
	}
}
