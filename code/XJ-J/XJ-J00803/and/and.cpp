#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,m;
	cin>>n>>m;
	int num=0,r[n],sum=0;
	for(int i=0;i<n;i++){
		cin>>r[i];
	}
	for(int i=0;i<n;){
		int maxid=i;
		for(int j=i+1;j<n;j++){
			if(r[j]>=r[maxid]){
				int a=r[j];
				r[j]=r[maxid];
				r[maxid]=a;
				maxid=j;
			}
		}
		if(r[i]>=r[i+1]){
			i++;
		}
	}
	sum=r[0];
	for(int i=1;i<m;i++){
		sum=sum&r[i];
	}
	cout<<sum;
	return 0;
}