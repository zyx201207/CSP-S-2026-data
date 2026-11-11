#include<bits/stdc++.h>
using namespace std;
int n=0,a[200004]={0},m=0,b=0;
int c(int d,int e,int f){
	if(e>m)return f;
	int g=0;
	for(int i=d+1;i<n;i++)g=max(g,c(i,e+1,f&a[i]));
	return g;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	int j=0;
	for(int i=0;i<n;i++)j=max(j,c(i,2,a[i]));
	cout<<j;
	fclose(stdin);
	fclose(stdout);
}