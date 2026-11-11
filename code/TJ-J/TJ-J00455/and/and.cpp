#include<bits/stdc++.h> 
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.in","w",stdout);
	int n,k;
	unsigned int a[200005];
	cin>>n>>k;
	for(int i=1;i<=n;i++)  cin>>a[i];
	sort(a+1,a+n+1,cmp);
	int sum=a[1];
	for(int i=2;i<=k;i++){
		sum=sum&a[i];
	}
	cout<<sum;
	return 0;
}
