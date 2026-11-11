#include<bits/stdc++.h>
using namespace std;
const int N=18,M=5,K=15;
string c1[K],c2[K];
string s1[N][M],s2[N][M];
int n,m,r,A,B,C,D,F;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>s1[N][M]>>s2[N][M];
		}
	}
	for(int k=1;k<=r;k++){
		cin>>c1[k]>>c2[k];
	}
	if(c1[k]!=c2[k]){
		continue;
	}else if(c1[k]==c2[k]&&s1[i][A]=s2[i][B]||s1[i][B]=s2[i][C]||s1[i][D]=s2[i][F]){
		cout<<"1111";
	}else if(s1[i][A]&&s2[i][C]){
		cout<<"1110"; 
	}else if(s1[i][A]&&s2[i][D]||s1[i][A]&&s2[i][f] || s1[i][B]&&s2[i][D]||s1[i][B]&&s2[i][f] || s1[i][C]&&s2[i][D]||s1[i][C]&&s2[i][f] || s1[i][D]&&s2[i][A]||s1[i][D]&&s2[i][B]||s1[i][D]&&s2[i][C] || s1[i][F]&&s2[i][A]||s1[i][F]&&s2[i][B]||s1[i][F]&&s2[i][C]){
		cout<<"1100"; 
	}else cout<<"1000";
	return 0;
}
