#include<bits/stdc++.h>
using namespace std;
long long n,m;long long maxx=1;long long pos=1;
long long a[500005],cha[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(long long i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    for(long long i=2;i<=n;i++){
        cha[i]=cha[i-1]+(a[i]-a[i-1])*(i-1);
    }
    for(long long i=2;i<=n;i++){
        if(cha[i]>m){
            while(cha[i]-cha[pos]>m){
                pos++;
            }
        }
        maxx=max(maxx,i-pos+1);
    }
    cout << maxx;
    return 0;
}

