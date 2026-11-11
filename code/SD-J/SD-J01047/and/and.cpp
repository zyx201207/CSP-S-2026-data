#include<bits/stdc++.h>
using namespace std;int a[200010];int n,m,max1=0;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n,cmp);
	for(int i=n-1;i>=m-1;i--){
		int y=a[i];
		for(int j=1;j<m;j++)
			y&=a[i-j];
		if(max1<y)max1=y;}
	cout<<max1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
