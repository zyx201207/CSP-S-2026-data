#include <bits/stdc++.h>
using namespace std;
long long a[100000],sum,sum1;
int n,m;
bool cmp(int x, int y){
    return x>y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    for(int i=1; i<=n; i++){
        if(m=1){
            sort(a+1,a+n+1,cmp);
            cout<<a[1];
            break;
        }
        if(m=2){
            for(int j=1; j<=n; j++){
                if(j==i) {break;}
                sum+=a[i] & a[j];
                if(sum>sum1){
                    sum1=sum;
                }
            }
            cout<<sum;
        }
    }
    return 0;
}

