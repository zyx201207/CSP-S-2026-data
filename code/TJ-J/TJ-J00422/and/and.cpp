#include<iostream>
#include<algorithm>
using namespace std;
int a[200005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	int y=0;
	for(int i=0;i<=n-m;i++){
		int p=a[i];
		for(int j=i;j<i+m;j++){
			p=p&a[j];
		}
		y=max(y,p);
	}
	
	cout<<y;
	return 0;
}
