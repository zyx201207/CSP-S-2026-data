#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001],s=0;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]&&a[i+1]>s){
			s=a[i]&&a[i-1];
		}
	}
	cout<<s+11;
	return 0;
}

