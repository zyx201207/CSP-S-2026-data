#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	freopen("string.out", "w", stdout);
    freopen("string.in", "r", stdin);
    int s,n,a[100005],t=0,l=0,m;
    cin>>s;
    for(int i=0;i<s;i++){
    	cin>>n>>m;
    	for(int j=0;j<n;j++){
    		a[l]=m;
    		l++;
		}
	}
	for(int i=0;i<l;i++){
		if(a[i]!=a[l]){
			t++;
			l--;
		}
	}
	cout<<t;
    fclose(stdout);
	fclose(stdin);
	return 0;
}
