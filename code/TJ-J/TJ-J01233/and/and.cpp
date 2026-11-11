#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	int a[200005],m,n,big=0;
	cin>>n>>m;
	for(int i=1;i++;i<=n){
		cin>>a[i];
	}
	for(int i=1;i++;i<n){
		for(int s=i+1;s++;s<=n){
			if(a[i]&a[s]>big){
				big=a[i]&a[s];
			}
		}
	}
	cout<<big;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
