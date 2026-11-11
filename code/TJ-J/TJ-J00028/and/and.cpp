#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200009];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    if(m=1)cout<<a[n];
    if(m=n){
    a[0]=a[1];
    for(int i=1;i<n;i++)
    a[0]=a[0]&a[i];
    cout<<a[0];
	}
    return 0;
}
