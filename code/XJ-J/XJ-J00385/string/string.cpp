#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,b[1000],g;
	cin>>a;
	for(int i=0;i<a*2;i++){
		cin>>b[i];
	}
	for(int i=1;i<a;i+=2){
		if(b[i]==b[i+2]){
			cout<<0;
			break;
		}
		if(b[i]*b[i+1]){
			g++;
		}	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}