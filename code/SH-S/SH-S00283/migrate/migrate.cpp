#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,c[1000],sum,x,v;
	cin>>n>>m;
	for(int h=0;h<n;h++){
		cin>>c[h];
		if(h>0){
			if(c[h]==c[h-1]+1 or c[h]==c[h-1]){
				sum=sum+1;
				x=c[h]+c[h-1]+1;
				v=c[h]+c[h-1];
			}
			else if(v+1==c[h] or v==c[h] or x==c[h] or x+1==c[h]){
				sum=sum+1;
				v=c[h]+c[h-1];
				x=c[h]+c[h-1];
			}
		}
	}
	if(sum>m){
		cout<<m;
	}
	else
		cout<<sum;
	
	return 0;
} 
