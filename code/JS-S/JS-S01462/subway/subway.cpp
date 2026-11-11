#include<bits/stdc++.h>
using namespace std;
int c,n,d;
long long m,q;
long long w[100000+1];
int a[500+1][100000+1];
long long t[500+1][100000+1];
int k[501];
long long ms=7e+9;
void dfs(int x,int y,long long s){
	int abs=x;
	if(x==y && s<ms && s>0){
		ms=s;
		return ;
	}
	for(int i=1;i<=n;i++){
		for(int z=1;z<=k[i];z++){
			if(a[i][z]==x){
				a[i][z]=0;
				s+=t[i][z];
				for(int j=1;j<=k[i];j++){
					if(a[i][j]!=0){
						x=a[i][j];
						a[i][j]=0;
						s+=t[i][j];
						dfs(x,y,s);
						s-=t[i][j];
						a[i][j]=x;
						x=abs;
					}
				}
				a[i][z]=abs;
				s-=t[i][z];
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		int q1,q2;
		cin>>q1>>q2;
		dfs(q1,q2,w[q1]+w[q2]);
		cout<<ms;
		ms=7e+9;
	} 
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
