#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define TIE ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int N=2e5+5,M=2005;
int n,m,a[N];
int pf1,pfn;
int f[M][M];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	TIE;
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
		if(m==1) pf1=max(pf1,a[i]);//Æ­·Öing 
		if(m==n){
			if(i==1){
				pfn=a[i];
				continue;
			}
			pfn=pfn&a[i];
		}
		
	}
	
	if(m==1){//Æ­·Öing 
		cout<<pf1;
		return 0; 
	}
	if(m==2){
		int pf2=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				pf2=max(pf2,a[i]&a[j]);
			}
		}
		cout<<pf2;
		return 0;
	}
	if(m==n){
		cout<<pfn;
		return 0;
	}
	
	memset(f,-0x3f,sizeof f);
	f[0][0]=f[0][1]=f[1][0]=0;
	f[1][1]=a[1];
	for(int i=2;i<=n;i++){
		f[i][0]=0;
		for(int j=0;j<=min(i,m);j++){
			if(j!=0) f[i][j]=max(f[i-1][j],f[i-1][j-1]&a[i]);
			else f[i][j]=f[i-1][j];
		}
	}
	cout<<f[n][m];
	return 0;
}
/*
3 3
1 1 3

4 2
3 15 12 12

5 3
31 3 1 15 7
*/
