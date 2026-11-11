#include<iostream> 
#include<cmath>
using namespace std;
long long m,n,lon[100000000][100000000],a[100000000]={1},ag,bi=20000000000,sm=1;
bool t=false;
int main(){
	cin>>m>>n;
	ag=n;
	for(int i=1;i<=m;i++){
		cin>>a[i];
		if(a[i]<=0){
			if(a[i]<sm){
				sm=a[i];
			}
			t=true;
		}
	}
	if(t){
		for(int i=1;i<=m;i++){
			a[i]=a[i]+abs(sm)+1;
		}
	}
	freopen("crystal.in",'r',stdin);
	freopen("crystal.out",'w',stdout);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j || i>j){
				lon[i][j]=2000000000;
			}
			else{
				lon[i][j]=a[j]-a[i];
			}
			
		}
	}
	for(int j=m;j>=1;j--){
		for(int i=1;i<=m;i++){
			if(n-lon[i][j]>=0){
				n-=lon[i][j];
				a[i]+=1;
			}
		}
		n=ag;
	}
	for(int i=1;i<=m;i++){
		if(a[i]<=bi){
			bi=a[i];
		}
	}
	cout<<bi;
	return 0;
}
