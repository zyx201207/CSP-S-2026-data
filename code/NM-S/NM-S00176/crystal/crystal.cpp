#include <bits/stdc++.h>
using namespace std;
long long a[1005], cnt = 0, s[1005],b[1005],b2[1005],s3[1005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
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
    for(long long i = 1; i <= n; i++){
    	for(long long j = i + 1; j <= n; j++){
    		b2[i] = max((a[j] - a[i]),b2[i]);
    	}
    	s3[i] = b2[i] - b[i];
	}
    //int l,r;
    //cin>>l>>r;
    //cout<<s[r] - s[l-1] <<" ";
    long long maxn = -1;
    for(long long i = 1; i <= n; i++){
    	for(long long j = i + 1; j <= n; j++){
    		if((s[j] - s[i-1] + s3[i])<= m){
    			maxn = max(maxn, (j-i));
			}
		}
	}
			cout<<maxn;
    return 0;
}
