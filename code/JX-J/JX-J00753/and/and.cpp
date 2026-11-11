#include<bits/stdc++.h>
using namespace std;
int n,m,k=1;
int a[20005],b[20005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=n;i>=m;i--){
    b[k]=a[i];k++;
    }
    if(m==1){cout<<a[n];return 0;}
    else if(b[1]==b[2]+1||b[1]==b[2]-1)cout<<"0";
    else cout<<b[k];
	return 0;
}
