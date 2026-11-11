#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,sum=0;
    cin>>n>>m;
    int a[200009];
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	sort(a,a+n);
	cout<<a[n-1]&&a[n-2];
	 return 0; 
}
