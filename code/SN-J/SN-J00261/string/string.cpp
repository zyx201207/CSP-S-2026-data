#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int N=2e5+5;
int a[N];
char c[N];
int main(){
	fropen("string.in","r",stdin);
	frepen("string.in","m",stdout);
	cin >>n;
    for (int i=1;i <=n;i++){
    	cin >>a[i]>>c[i];
    	for (int j=1;j <=a[i];j++){
		    s +=c[i];
	    }
	    
   }
int sum=0;
	for(int i=0;i<=n/2;i++){
		if(s[i] !=l[i]){
			sum++;
	   }
   }
	cout <<sum;
	return 0;
}
