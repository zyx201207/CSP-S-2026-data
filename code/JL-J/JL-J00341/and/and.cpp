#include <iostream>
using namespace std;
int main(){
	int m,n;
	cin>>n>>m;
	int a[500000];
	int b,sum=0;
	freopen("and.in","r",stdin);
	//for(int i=1;i<=n;i++){
		//cin>>a[i];
	//}
	b=(a[1]&a[2]);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=m;j++)
			b=b&a[j+1];
		if(sum<b)
			sum=b;
		b=(a[i+1]&a[i+2]);
	}
	//cout<<sum;
	freopen("and.out","w",stdin);
	return 0;
}
