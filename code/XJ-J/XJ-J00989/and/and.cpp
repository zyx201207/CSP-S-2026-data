#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
	}
	int b[n+5];
	for(int i=1;i<=n;i++){
		while(a[i]!=0){
			b[i]=(b[i]*10)+(a[i]%2);
			a[i]=a[i]/2;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}