#include<bits/stdc++.h>
using namespace std;
long long a[1000010],b[1000010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,x=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++){
		b[i]=a[i];
	}
	sort(b+1,b+m+1);
	cout<<b[1];
	fclose(stdin);
	fclose(stdout);
	return 0;
 }
