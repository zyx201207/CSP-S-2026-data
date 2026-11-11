#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,ns[10001],nl[10001]={0},ms[1001][201]={0},tong[10001]={};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ns[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int a,b=1;
			a=ns[j];
			while(b!=nl[i]+1){
				if(ms[i][b]==ns[j]){
					ms[i][nl[i]]=0;
					nl[i]--;
				}else{
					b++;
				}
			}
			nl[i]++;
			ms[i][nl[i]]=ns[j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=nl[i]+1;j++){
			tong[ms[i][j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<tong[i];
	}
    fclose(stdin);
    fclose(stdout);
}
