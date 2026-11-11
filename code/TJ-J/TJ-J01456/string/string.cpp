#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout);
	int n,a,b,c;
	cin>>n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(a>b||a>c){
				cout<<i+j;
			}
		}
	
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
