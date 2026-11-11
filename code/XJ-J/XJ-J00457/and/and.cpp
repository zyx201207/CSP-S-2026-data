#include<bits/stdc++.h>
using namespace std;
bool f(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int r;
	long long a[100005];
	string b[100005];
	for(long long i=0;i<n;i++)  cin>>a[i];
	sort(a,a+n,f);
	cout<<a[m-1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}