#include <iostream>
using namespace std;
 
int n=0,t=0,sum=0;
int x[2000000]={0};

int jdz(int a,int b){
	int c =a-b;
	if(c<0){
		c=0-c;
	}
	return c;
}

int xiaomain(){
	n=0,t=0,sum=0;
	cin>>n>>t;
	for(int i =0;i<n;i++){
		cin>>x[i];
	}
	for(int i = 0;i<n;i++){
		for(int j =i;j<n;j++){
			int l = jdz(i,j);
			if(l>t){
				if(l%t>0){
					sum++;
				}
			}
		}
	}
	return sum; 
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=0,t=0;
	cin>>c>>t;
	for(int i =0;i<t;i++){
		cout<<xiaomain()<<endl;
	}
	return 0; 
}
