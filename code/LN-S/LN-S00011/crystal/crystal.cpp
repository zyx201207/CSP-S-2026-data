#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
        if(b[i]>m){
			cout<<i-1;
			return 0;
		}
    }
    cout<<n;
	return 0;
}
