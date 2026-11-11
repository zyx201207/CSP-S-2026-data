#include<bits/stdc++.h>
using namespace std;
int n,m,mmm=0;
int za[37],mcc;
int mb[200007][37];
void qing(int x){
	for(int i=0;i<n;i++){
		if(mb[i][x]==0){
			for(int j=0;j<=x;j++){
				if(mb[i][j]==1){
					za[j]--;
				}
				mb[i][j]=0;
			}
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	memset(za,0,sizeof(za));
	memset(mb,0,sizeof(mb));
	for(int i=0;i<n;i++){
		cin>>mcc;
		for(int j=0;mcc>=1;j++){
			if(mcc%2==1){
				za[j]++;
				mb[i][j]=1; 
			}
			mcc/=2;
			mmm=max(mmm,j);
		}
	}
	while(mmm>=0){
		if(za[mmm]<m){
			za[mmm]=0;
		}
		else{
			qing(mmm);
		}
		mmm--;
	}
	int he=0;
	for(int i=0;i<33;i++){
		if(za[i]>0){
			he+=pow(2,i);
		}
	}
	cout<<he;
	return 0;
} 
