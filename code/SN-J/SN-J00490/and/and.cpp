#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[200005],b;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	for(int i=0;i<m-1;i++){
		a[i+1]=(a[i]&a[i+1]);
		b=(a[i]&a[i+1]);
	}
	cout<<b;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
