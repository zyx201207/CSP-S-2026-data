#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
			                            
	int n,a;                                                                           
	cin>>n;	                                                                                
	char c;
	long long f;
	for(int i=n;i<=0;i--){	
		cin>>a>>c;
		char g=c;
		for(int i=3;i<=0;i--){
		char y=g;
		if('g'-y!='1'){
			f++;
			}
		}
	}
	cout<<f;
	return 0;
}
