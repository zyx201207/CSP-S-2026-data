#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a[2006];
	long long max=-1;
	for(int i=0;i<=2005;i++){
		a[i]=-1;
	}
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=0;i<n;i++){
			if(max<a[i]){
				max=a[i];
			}
		}
	cout<<max;}
	
	if(m==n){
		max=a[0];
		for(int i=0;i<n;i++){
			max=(max&a[i]);
		}
		cout<<max;
	}
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if((a[i]&a[j]>max)){
					max=(a[i]&a[j]);
				}
			}
		}
	cout<<max;}
	
    return 0;
}