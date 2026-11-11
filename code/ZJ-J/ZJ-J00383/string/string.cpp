#include<bits/stdc++.h>
using namespace std;
char c,a[1000000005]={};
int n,x,y=0,s=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		cin>>c;
		for(int j=y;j<x+y;j++)a[j]=c;
		y+=x;
	}
	for(int i=0,j=y-1;i<=j;i++,j--){
		if(a[i]!=a[j])s++;
	}
	cout<<s;
	return 0;
}