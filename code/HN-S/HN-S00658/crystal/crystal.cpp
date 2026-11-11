#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	int sum=0,w=0;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int j=0;j<n;j++){
		sum=0;
		for(int i=0;i<n;i++){
			if(a[i]==a[j]){
				sum++;
			}else if(a[i]<a[j]){
				if(a[i]+m>=a[j]){
					m-=a[j]-a[i];
					sum++;
				}
			}
		}
		if(sum>w){
			w=sum;
		}
	}
	cout<<w+1;
	return 0;
} 
