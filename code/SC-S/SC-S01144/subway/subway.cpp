#include <bits/stdc++.h>
using namespace std;
const int N=600;
long long c,n,m,d,q,l,r; 
long long w[N];//口到枢纽   
long long num[N][N],road[N][N],tot[N];
int main(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int j;
		cin>>j;
		tot[i]=j;
		for(j;j>0;j--){
			int x;
			cin>>x;
			cin>>road[i][x];
			num[x][i]=1;
	}
}
	while(cin>>l>>r){
		cout<<"genshin";
	}
}