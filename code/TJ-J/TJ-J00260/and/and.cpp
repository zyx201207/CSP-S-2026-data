#include<bits/stdc++.h>
using namespace std;
int n,m,c;
int a[200001];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(m==1){
			c=max(a[i],c);
		}
		else if(m==2){
			c=max(a[i]&a[i+1],c);	
		}
		else if(m==3){
			c=max(a[i]&a[i+1]&a[i+2],c);
		}
		else if(m==4){
			c=max(a[i]&a[i+1]&a[i+2]&a[i+3],c);
		}
		else if(m==5){
			c=max(a[i]&a[i+1]&a[i+2]&a[i+3]&a[i+4],c);
		}
	}
	cout<<c;
	return 0;
} 
