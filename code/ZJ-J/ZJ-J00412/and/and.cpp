#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
int fh[50];
bool t[200005][50],flag;
long long ji;
long long fhz;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=32;i++)fh[i]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int tt=a[i];
		for(int j=1;j<=32;j++){
			t[i][j]=tt%2;
			tt/=2;
			if(tt==0)break;
		}
		
	}
	for(int j=31;j>=1;j--){
		ji=0;
		for(int i=1;i<=n;i++){
			if(t[i][j]==1)ji++;
			if(ji==m){
				flag=1;
				break;
			}
		}
		if(flag==1){
			for(int i=1;i<=n;i++){
				if(t[i][j]==0)
				for(int k=1;k<=32;k++){
					t[i][k]=0;
					t[i][0]=1;
				}
			}
		}
		flag=0;
		//
		
	}
	int js=0;
	//
	for(int i=1;i<=n;i++){
		if(t[i][0]==1)continue;
		js++;
		for(int j=1;j<=32;j++){
		if(fh[j]==1&&t[i][j]){
		}
		else{
			fh[j]=0;
		}
		}
		if(js==m)break;
	}
	//
	
	for(int i=1;i<=32;i++){
		fhz+=fh[i];
		for(int j=i+1;j<=32;j++){
			fh[j]*=2;
		}
	}
	cout<<fhz;
	return 0;
} 
/*
4 2
3 15 12 12
*/

   