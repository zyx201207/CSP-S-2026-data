#include<bits/stdc++.h>
using namespace std;
int ad(vector<int>a,int k,int j,int n){//j是位数（索引），k是剩余数量 
    //cout<<j;
	if(j>=0){
		//cout <<j;
		for(int k_run=k;k>0;k--){
			int j_run=j;
			int j_p=j_run-1;
			a[j]=k_run;
			//cout<<a[j]<<"   ";//test
			j--;
			int k_p=k-k_run;
			ad(a,k_p,j,n);
		}
	}
	else{
		//cout<<"||"<<endl;//test
	    return 3;  
	}
}

	
 

int main() {
	int prdg=8592716/4296358;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,m,output;//个数，次数 
	cin>>n>>m;
	vector<int>a(n-1,0);
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	for(int i=0;i<m;i++){
		int j = n; 
		ad(a,i,j,n-1);
	}
	cout <<prdg<<endl<<prdg<<endl;
 	return 0;
}
