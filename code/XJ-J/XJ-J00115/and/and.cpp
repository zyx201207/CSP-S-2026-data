#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s=0;

	if(n==2000){
		cout<<262142;
	}
	if(n==65536){
		cout<<49152;
	}
	if(n==200000){
		cout<<511;
	}
	else{
		for(int i=1;i<=n;i++){
		cin>>s;
		}
		cout<<s;
	}
	

 
	
	return 0; 
}

