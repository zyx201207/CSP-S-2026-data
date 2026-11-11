#include<bits/stdc++.h>
using namespace std;
long long w[10000];
long long k[1000][1000],u[1000][1000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,sum=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=2;i++){
		for(int j=1;j==1;j++){
			cin>>k[i][j];
		}
		for(int s=2;s<=2*k[i][1]+1;s++){
			cin>>k[i][s];
		}
	}
	for(int i=2;i<=2*k[1][1]+1;i+2){
		for(int j=2;j<=2*k[2][1]+1;j+2){
			if(k[1][i]==k[2][j]){
				sum+=k[1][i+1]+k[2][j+1];
			}
		}
	}
	for(int j=1;j<=q;j++){
		for(int i=1;i<=2;i++){
			cin >> u[j][i];
			sum+=w[j]+w[i];
		}
	}
	cout <<sum;
	return 0;
}