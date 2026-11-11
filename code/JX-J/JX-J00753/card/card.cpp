#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005],b[100005];
bool c[100005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    cin>>a[i];
    }
    for(int i=1;i<=n;i++){
    if(a[i]==a[i+1])cout<<"1";
    else{cout<<n-i+1;}
    }
	return 0;
}
