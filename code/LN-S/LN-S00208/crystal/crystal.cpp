#include<bits/stdc++.h>
using namespace std;
long long n,m,q,z;
long long a[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    long long w=n;
    sort(a+1,a+n+1);
    for(int i=1;i<=m;i++){
       if(a[1]+i==a[3]){
            q=m-i;
            if(a[2]+q==a[3]){
                for(int i=4;i<=n;i++){
                    if(a[i]==a[i-1]){
                        z++;
                    }else{
                        break;
                    }
                }
            }
        }
    }
    cout << 3+z;
    return 0;
}
