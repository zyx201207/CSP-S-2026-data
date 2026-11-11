//封雅芙 
//SN-J00792
//延安职业技术学院附属中学 
#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,m,r[120000];
	long long zs[50][50];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>r[i];
	}
	long long p=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<50;j++){
			if(r[i]==0){
				break;
			}else{
				zs[p][j] = r[i]%2;
				r[i] /= 2;
			}
		}
		p++;
	}
	for(int i=0;i<n;i++){
		cout<<zs[p][i];
	}
}
