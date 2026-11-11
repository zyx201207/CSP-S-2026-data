#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200000+100],cnt;
bool flag;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=1;j<n;j++){
            if(a[i]==a[j]){
                for(int k=i;k<n;k++){
                    a[k]=0;
                }
            }
        }
        for(int j=1;j<=n;j++){
            if(a[j]==i){
                cnt++;
            }
        }
        cout<<cnt<<" ";
    }
    return 0;
}
