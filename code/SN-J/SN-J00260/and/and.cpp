#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[20005];
int q;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    q=a[n-1];
    for(int i=n-2;i>n-m-1;i--)q&=a[i];
    cout<<q;
	return 0;
}


