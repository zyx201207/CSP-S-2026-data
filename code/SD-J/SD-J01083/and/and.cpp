#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int n,m,s=100005;
	cin>>n>>m;
	int a[100005];
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int j=0;j<i;j++){
			if(a[i]==a[j]&&a[i]<s){
				s=a[i];
			}
			else if(i=n-1){
				sort(a,a+n);
				cout<<a[3];
			}
		}
	}
	cout<<s;
return 0;
}
