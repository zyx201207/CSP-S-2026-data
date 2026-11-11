#include<bits/stdc++.h>
using namespace std;
long long n, m;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(a[1]==a[n]){
		if(m<n){
			cout<<max(m,n-m);
		}else{
			cout<<n;
	}
    for(long long i=1;1==1;i++){
        long long c=a[i+1]-a[i];
        if(m-i*c>0){
            m-=i*c;
        }else{
			cout<<i;
            return 0;
        }
    }
    return 0;
}
