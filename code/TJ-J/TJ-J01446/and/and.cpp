#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10008798];
bool cmp(int x,int y){
return x>y;}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	long long sum=a[0];
	for(int i=1;i<m;i++){
		sum=(sum&&a[i]);
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
return 0;
}
