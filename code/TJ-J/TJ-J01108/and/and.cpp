#include<bits/stdc++.h>
using namespace std;
int main(){

int n,m,s=0;
int a[100005]={0};
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
	if(a[i]^a[i-1]>a[i+1]^a[i]){
		s+=a[i]^a[i-1];
	}else{
		s+=a[i+1]^a[i];
	}
}
cout<<s<<endl;
return 0;	
} 
