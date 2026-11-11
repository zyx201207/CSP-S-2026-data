#include<iostream>
using namespace std;
int a[500010];
bool cmp(int x,int y){
	return x<y;
}
int main(){
	int n,m;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	
	return 0;
}
