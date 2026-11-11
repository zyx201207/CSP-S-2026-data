#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int m;
    int a[10000];
    char b[10000];
    for(int i=1;i<=m;i++){
        cin>>a[i]>>b[i];
    }
    int n=1;
    for(int i=1;i<=m;i++){
        n=n*a[m];
    }
    cout<<n/2;
    return 0;
}
