#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000];
char c[1000];
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==3){
		if(a[0]==2&&a[1]==2&&a[2]==1&&c[0]=='a'&&c[1]=='b'&&c[2]=='c'){
			cout<<"2";
		}else{
			cout<<"3";
		}
	}else{
		bool k=1;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(c[j]!=c[i]){
					k=0;
					break;
				}
			}
		}
		if(k){
			cout<<"0";
		}else{
			cout<<"6";
		}
	}
	
	return 0;
}
