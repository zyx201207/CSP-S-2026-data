#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a;
	cin>>a;
	double b[a];
	char d[a];
	char f[a];

	long long   zuixiao=0;
	for(int i=0;i<a;i++){
		cin>>b[i];
		cin>>d[i];
		
	}
	for(int i=a-1;i>=0;i--){
	f[i]=d[a-i-1];
	}
	
	
	for(int i=0;i<a/2;i++){
		if(d[i]!=f[i]){
			
			if(b[i]<b[a-i-1]){
				zuixiao+=b[a-i-1];
			}else{
			zuixiao+=b[i];
		}
		}
	}	
	
	
	printf("%d",zuixiao);
		fclose(stdin);
	fclose(stdout);
	return 0;
}