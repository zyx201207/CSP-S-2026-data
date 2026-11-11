#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;	
	int num=0;
	string c;
	int sum=0;
	int a[100010];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		cin>>c[i];
		for(int i=0;i<a[i];i++){
		a[i]=c[i];
	   }
 }
 for(int i=1;i<=n;i++){

	for(int i=1;i<=sum/2;i++){
		if(a[i]!=a[i+sum/2]){
			num++;
		}
		}
}
	cout<<num;
	return 0;
}
