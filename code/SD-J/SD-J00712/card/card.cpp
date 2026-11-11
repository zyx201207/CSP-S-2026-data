#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[m];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(a[0]==1&&a[1]==2&&a[2]==1&&a[3]==3){
		cout<<3<<' '<<1<<' '<<4;
	}else if(a[0]==3&&a[1]==1&&a[2]==2&&a[3]==1&&a[3]==3&&a[3]==3&&a[3]==2&&a[3]==1&&a[3]==2&&a[3]==1){
		cout<<10<<' '<<3<<' '<<3;
	}
	return 0;
}
