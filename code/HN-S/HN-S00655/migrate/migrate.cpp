#include<bits/stdc++.h>
using namespace std;
	int g,h;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long k[2000005][2000001];
	int a,b;
		int d=0;
	int l[2000005];
	cin>>a>>b;
	for(int j=0;j<b;j++){
		cin>>g>>h;
	for(int i=0;i<g;i++){
		cin>>k[j][i];
		sort(k[j][i],k[j][i]+2000001);
	}
}
	for(int i=0;i<b;i++){
		for(int j=0;j<g;j++){
		for(int v=0;v<g;v++){
			if(k[i][j]+d<=h){
				l[j]++;
			}
			if(d>=g)
			d=0;
			d++;
		} 
		}
	}
	return 0;
} 
