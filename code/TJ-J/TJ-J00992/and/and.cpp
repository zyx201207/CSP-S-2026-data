#include<bits/stdc++.h>
using namespace std;
int a[200010],b[200010],cnt=1;
bool g(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,g);
	cnt=a[1];
	for(int i=2; i<=m; i++){
		b[i]=a[i];
		cnt=b[i] & cnt;
	}
	cout<<cnt<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
