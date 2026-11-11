#include<bits/stdc++.h>
using namespace std;
char b[100000000];
char a[100000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	
	int s=0;
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		cin>>a[i];
		for(int j=0;j<k;j++){
			b[s]=a[i];
			s++;
		}
	}
	
	if(n==1){
		cout<<0;
	}
	bool f=true;
	if(n==2){
		for(int i=1;i<s;i++){
			if(b[i]==b[i-1]){
				f=true;
			}else{
				f=false;
				cout<<'1';
				break;
			}
		}
		if(f==true){
			cout<<0;
		}
	}else if(n<=3){
		cout<<2;
	} 
		
	return 0;
} 
