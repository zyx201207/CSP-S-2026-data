#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long big;
int a[500005],f[500005];
int geshu,geshu2;
int didian,didian2;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n-1;i++){
		big+=a[i];
	}
	big/=n-2;
	f[1]=1;
	int fgh=0;
	int g=0;
	for(int i=1;i<=n;i++){
		if(big>=a[i]){
			didian=i;
			fgh=a[i];
			
			if(g==0){
				didian2=i-1;
			}
			g++;
		}
		if(fgh!=a[i]){
			break;
		}
	}
	for(int i=1;i<=didian2;i++){
		f[i]=a[didian2]-a[i];
	}
	for(int i=didian2;i>=1;i--){
		if(f[i]<=m){
			geshu2+=1;
			m-=f[i];
		}
		else{
			break;
		}
		
	}
	for(int i=1;i<=didian;i++){
		f[i]=a[didian]-a[i];
	}
	for(int i=didian;i>=1;i--){
		if(f[i]<=m){
			geshu+=1;
			m-=f[i];
		}
		else{
			break;
		}
		
	}
	cout<<max(geshu,geshu2);
	return 0;
}
