#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
    int a[n+1];
	for(int i=0;i<=n-1;i++){
	cin>>a[i];
    }
	return 0;	
}
