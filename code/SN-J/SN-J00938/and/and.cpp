#include <bits/stdc++.h>
using namespace std;
int a[2000010],s[2000010];
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	int n,m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=100;j++){
			s[j]=a[i]%2;
		}                               
	}
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}



