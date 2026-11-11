#include <bits/stdc++.h>
using namespace std;
int n,m,sum[1010000];
int b[1010000];
int a[101000];
bool find (int x,int gs){
	if(gs==0){
		return 0;
	}
	for(int i=1;i<=gs;i++){
			if(a[i]==x){
				return 1;
			}
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;//4 3
	for(int i=1;i<=n;i++){
		int c;//1 2 1 3
		cin>>b[i];
	}
	int gs=0;
	for(int i=1;i<=n;i++){
		if(!find(b[i],gs)){
			a[gs+1]=b[i];
			gs++;
		}else{
			int jian=0;
			for(int j=find(b[i],gs);j<=gs;j++){
				a[j]=0;
				jian++;
			}
			gs-=jian;
			a[gs+1]=b[i];

		}
		for(int v=1;v<=gs;v++){
			sum[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<' ';
	}
	return 0;
}
