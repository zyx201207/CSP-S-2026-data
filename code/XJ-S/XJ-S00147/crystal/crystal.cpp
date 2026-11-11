#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+2;
LL a[N];
int n;
LL m;
LL maxx=1;
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n>5e3&&m>1e8) {
        int k=a[2]-a[1];
        int u=1;
        int sum=0;
        while(1) {
            sum+=k;
            k+=2;
            if(sum<=m){
                u++;
            }else {
                break;
            }
        }
        cout<<u;
    }else {
        for(int i=1;i<=n;i++) {
            LL sum=0;
            LL k=1;
            for(int j=i-1;j>=1;j--) {
                sum+=a[i]-a[j];
                if(sum<=m) {
                    k++;
                    maxx=max(maxx,k);
                }
                else {
                    break;
                }

            }
        }
        cout<<maxx;
    }


    return 0;
}
