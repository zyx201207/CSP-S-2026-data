#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	freopen("and.out", "w", stdout);
    freopen("and.in", "r", stdin);
    int a,b,c[10005],l=0;
    cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>c[i];
	}
	for(int i=0;i<a;i++){
		for(int j=0;j<a-1;j++){
			if(a[i]&a[j]>l){
				l=a[i]&a[j];
			}
		}
	}
	cout<<l;
    fclose(stdout);
	fclose(stdin);
}
