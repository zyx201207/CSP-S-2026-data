#include <bits/stdc++.h>
using namespace std;
int n,sum=0,x;
int p[200001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n>>x;
    for(int i=1;i<=n;i++)
    {
        cin >> p[i];
    }
    sort(p+1,p+1+n);
    while(0x10000000%p[n-x+1]==0)
    {
        n--;
    }
    for(;x>1;x--){
        for(int i=1;i<=n-x;i++)
        {
            sum=max(sum,p[n-x+1] & p[i]);
        }
    }
    cout << sum;
    return 0;
}


