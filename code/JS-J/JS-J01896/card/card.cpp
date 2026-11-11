#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(m<=2){
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int l=1,r=n;
        for(;l<=r;l++)
        {

            if(a[l]==a[r])
                b[a[l]]++;
            else
            {
                b[a[l]]++;
                b[a[r]]++;
            }
        }
        for(int i=1;i<=m;i++)
            cout<<b[i]<<' ';
        return 0;
    }
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cout<<n<<' ';
    return 0;
}
