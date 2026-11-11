#include<bits/stdc++.h>
using namespace std;
const int N=200001;
const int M=10001;
int c,t;
int cnt[N]={0};
int n[M],d[M];
int x[500][N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i]>>d[i];
		cnt[i]=0;
		for(int j=1;j<=n[i];j++){
			cin>>x[i][j];
		}
		int k=x[i][2]-x[i][1];
		int q=d[i]/k;
		int ans_1=(q+1)/2;
		int ans_2=q/3;
		cnt[i]=2*(ans_1-ans_2)+ans_2;
	}
    for(int i=1;i<=t;i++){
		cout<<cnt[i]<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}