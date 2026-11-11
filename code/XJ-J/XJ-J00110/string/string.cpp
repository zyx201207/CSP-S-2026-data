#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","W",stdout);
	int n;
	cin>>n;
	char ch[10*10*10*10*10*10+5];
	int js=0,k=0;
	for(int i=0;i<n;i++){
		int a;
		char ch1;
		cin>>a;
		js+=a;
		cin>>ch1;
		for(int j=0;j<a;j++){
			ch[k++]=ch1;
		}	
	} 
	int h=0;
	for(int i=0;i<js/2;i++){
		char b=ch[i];
		if(b!=ch[js-1]){
			h++;	
		}
	}
	cout<<h;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
