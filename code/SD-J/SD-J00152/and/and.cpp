#include<bits/stdc++.h>
using namespace std;
bool px(int x,int y){
	return x>y;
}
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	int a[100000]={};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,px);
	for(int i=1;i<m;i++){
		a[0]&=a[i];
	}
	printf("%d",a[0]);
	return 0;
}//Trick||Treat!
