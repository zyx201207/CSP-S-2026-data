#include<bits/stdc++.h>
using namespace std;
int n,a[2100000],b[2100000],m;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in",'r',stdin);
	freopen("and.out",'w',stdout);
	int d=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for (int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			b[d]=a[i]&&a[j];
			d+=1;
		}
	}
	sort(b,b+n,cmp);
	cout<<b[0];
	return 0;
}