#include <iostream>
using namespace std;
int c;
int n;
int m;
int d;
int q;



int main(){
	cin>>c;
	cin>>n;
	int xianlu[n];
	int jingguo[n][100];
	int ztzt[n][100];
	cin>>m;
	int zhanko[m];
	cin>>d;
	cin>>q;
	int qid[q];
	int zhd[q]; 
	for (int i=0;i<m;i++){
		cin>>zhanko[i];
	}
	for (int i=0;i<n;i++){
		cin>>xianlu[i];
		for(int j=0;j<xianlu[i];j++){
			cin>>jingguo[i][j];
			cin>>ztzt[i][j];
		}
	}
	int ans;
	int answ[q];
	int mina=100;
	for (int i=0;i<q;i++){
		cin>>qid[i];
		cin>>zhd[i];
		int loca=qid[i];
		for (int j=0;j<m;j++){
			for (int k=0;k<m;k++){
			
				if (jingguo[j][k]==loca){
					loca=k;
					int qi=qid[i];
					int zh=zhd[i];
					
					ans=zhanko[qi]+zhanko[zh]+loca;
					mina=min(ans,mina);
				}
			}
		}
		answ[i]=mina;
			
		
	}
	for (int i=0;i<q;i++){			
		cout<<answ[i]<<endl;
	}
		
		
		
	
	//////
	
	
	
	
	
	
	return 0;
} 
