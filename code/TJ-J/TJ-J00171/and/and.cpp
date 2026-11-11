#include<bits/stdc++.h>
using namespace std;
int a[200009];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	int sum=a[1];
	for(int i=1;i<=n&&m>0;i++){
		sum=sum&a[i];
		m--;
	}
	cout<<sum;
	return 0;
}

