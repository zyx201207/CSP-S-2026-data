#include <bits/stdc++.h>

using namespace std;

int a[1000009];
int main()
{
   freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c,t;
    cin>>c>>t;
    for(int qq=1;qq<=t;qq++){
        int n,d,sum=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]-a[i-1]>d){
                n=i-1;
                break;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                    int q=j-i;
                    if(q%d==0||q<=d||q/d>=2){
                        continue;
                    }
                    sum++;
            }
        }
        cout<<sum<<endl;
    }

    return 0;
}
