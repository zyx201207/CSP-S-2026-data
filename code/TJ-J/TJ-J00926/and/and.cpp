#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ma=0;
	cin>>n>>m;
	int a[200005];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]&a[j]>ma)
				ma=a[i]&a[j];
		}
	}
	cout<<ma;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
