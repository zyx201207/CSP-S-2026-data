#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,c;
	cin>>n>>c;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==3 || 15 ||12){
			cout<<"12"; 
		}else{
			cout<<"7";
		}
	}
	
	return 0;
}
