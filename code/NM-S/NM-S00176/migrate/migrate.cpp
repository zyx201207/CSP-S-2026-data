#include <bits/stdc++.h>
using namespace std;
long long a[1005], cnt = 0, s[1005],b[1005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long  n,m;
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i = 1; i < n; i++){
    	b[i] = a[i+1] -a[i];
	}
    for(int i = 1; i < n; i++){
        s[i] = b[i]+s[i-1];
    }
    //int l,r;
    //cin>>l>>r;
    //cout<<s[r] - s[l-1] <<" ";
    long long maxn = -1;
    for(long long i = 1; i <= n; i++){
    	for(long long j = i + 1; j <= n; j++){
    		if((s[j] - s[i-1] )<= m){
    			cout<<j<<"   "<<i<<endl;
			}
		}
	}
	cout<<maxn;
    return 0;
}
