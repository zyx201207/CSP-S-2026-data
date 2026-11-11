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
	freopen("and,out","w",stdout);
	
	return 0;
} 
