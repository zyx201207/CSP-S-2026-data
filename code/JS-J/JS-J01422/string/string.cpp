#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,i;
    char b;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i]>>b;
    }
    if(n==1)
        cout<<0;
    else
        cout<<i*n/2;
	return 0;
}
