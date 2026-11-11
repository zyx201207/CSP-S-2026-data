#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","W",stdout);
	long long n,m,a[200005],bigger=-3,land,bn;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]>=bigger)bn=i;
        bigger=max(a[i],bigger);
    }
    land=bigger;
    bigger=-3;
    a[bn]=0;
    for(int j=1;j<=n;j++){
        for(int i=1;i<=n;i++){
            if(a[i]&land>=bigger)bn=i;
            bigger=max(a[i]&land,bigger);
        }
        land=bigger;
        bigger=-3;
        a[bn]=0;
    }
    cout<<land;
	return 0;
}
