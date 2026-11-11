#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int su=0;
	int n,m;
	cin>>n>>m;
	int a[n]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	sort(a+0,a+n);
	int zu=0;
	int min=a[n-1];
	for(int i=0;i<n;i++){
		if(min<a[i+1]-a[i] and a[i+1] >0 and a[i+1]!=a[i]){
			min =a[i+1]-a[i];
			zu=i;
		}else if(a[i+1]<0 and min< -a[i+1]-a[i] and a[i+1]!=a[i]){
			min = -a[i+1]-a[i];
			zu=i;
			
		}
		if(a[i]==a[i+1]){
			zu=i;
			break;
		}
	}
	
	for(int i=0;i<n;i+=2){
	     if(a[zu]-a[i] <=m and m>0){
			a[i] = a[zu];
			m-=a[zu]-a[i];
		}	
	}
	for(int i=0;i<n;i++){
		if(a[zu]==a[i]){
			su++;
		}
	}
	cout<<su;
	
	return 0;
} 
