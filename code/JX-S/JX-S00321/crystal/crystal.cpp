#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal3.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	sort(a+1,a+n+1);
	int v=1;
    for(int i=2;i<=n;i++){
        if((a[i]-a[i-1])<=m){
            m-=(a[i]-a[i-1])*v;
            v++;
        }

        else{break;}

    }
    cout<<v;
	return 0;
}
