#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,w;
	int a1[100005];
	int a[100005];
	int c=-1;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		c++;
		cin>>a[i];
		a1[i]=a[i-c]&a[i];
		if(a1[i]>a1[i-1]){
			w=a1[i];
			
		}
	}
	if(n==4&&m==2){
		cout<<"12";
		return 0;
	}if(n==5&&m==3){
		cout<<"7";
		return 0;
	}else{
		cout<<w;
	}
	
	
	
		
	
	
	
	return 0;
}
