#include<bits/stdc++.h> 
using namespace std;
long long int c,t;
int main(){
	cin>>c>>t;
	for(int z=1 ; z<=t ; z++){
		long long int n=0,d=0,x=0,a[1000000];
		cin>>n>>d;
		for(int i=0 ; i<n ;i++){
			cin>>a[i];
		}
		for(int i=1 ; i<n-1 ; i++){
			if((a[i]-a[0]<=d || a[0]-a[i]<=d)&&(a[i]-a[5]<=d || a[5]-a[i]<=d)){
				x++;
			}
		}
		cout<<x-1<<endl;
	}
	
	return 0;
}
