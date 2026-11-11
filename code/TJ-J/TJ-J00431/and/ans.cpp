#include<bits/stdc++.h>
using namespace std;
int a[2005];
int n,m;
int ay2(int a,int b){
	int x=0,y=0;
	while(a--){
		x+=a%2;
		x*=10;
	}
	while(b--){
		y+=b%2;
		y*=10;
	}
	int i=max(x,y);
	while(i--){
		
		
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==1){
		cout<<a[n];
	}
//	else if(m==2){
//		
//	}
	return 0;
	
} 
 
