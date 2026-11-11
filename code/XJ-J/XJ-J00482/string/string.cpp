#include <iostream>
#include <cstdio>


using namespace std;
int main() {
     freopen("string.in","r",stdin);
      freopen("string.out","w",stdout);
      char b[100]={},c[100]={};
	int n=0,nn=0,j=0,sum=0,kk=0;
	char a;
	cin>>n;
		for(int i=0;i<n;i++){
		cin>>nn>>a;
		for(j;j<nn+j;j++){
			b[j]=a;
		}
		j+=1;
}
    for(int i=0;i<j;i++){
    	kk=j-1;	
    	if(b[kk]!=b[i]) sum++; 
    		kk--;
}
	cout<<sum;
	return 0;
}