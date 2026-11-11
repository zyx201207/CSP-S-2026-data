#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int tong[m+2]={0};
	int pai[n+2]={0};
	for(int i=1;i<=n;i++){
		cin>>pai[i]; 
	}
	int x=n;
	int ai=1;
	while(x--){
		int da[n+2]={0};
		int j=ai;
		int y=n;
		while(y--){
			int f=0;
			int mi;
			for(int i=ai;i<j;i++){
				if(pai[j]==da[i]){
					f=1;
					mi=i;
				}
			}
			if(f==1){
				for(int i=mi;i<j;i++){
					da[i]=0;
				}
				da[j]=pai[j];
			}else{
				da[j]=pai[j];
			}
			j++;
		}
		for(int i=1;i<=j;i++){
			if(da[i]!=0){
				tong[da[i]]++;
			}
		}
		ai++; 
	}
	for(int i=1;i<=m;i++){
		cout<<tong[i];
	}
	return 0;
}
