//刘立恒交大附中 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a,b[10000],c;
	char n[10000];
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>b[i]>>n[i];
	}
	if(n[1]==n[2]){
		c=0;
    }else{
    	c=1;
	}
	if(a==1){
		c=0;
	} 
	cout<<c; 
	fclose(stdin);
	fclose(stdout);
    return 0;
}

