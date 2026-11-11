#include<bits/stdc++.h>
using namespace std;
long long a[100000005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}cout<<a[n];
    return 0;
}

