#include<bits/stdc++.h>
using namespace std;
int a[300005];
int b[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int i=1;i<=n;i++){
        int c[500005]={0},ct=0;
        for(int j=i;j<=n;j++){
            int d=b[j];
            for(int k=1;k<=ct;k++){
                if(c[k]==d){
                    ct=k-1;
                    break;
                }
            }
            c[++ct]=d;
        }

        for(int j=1;j<=ct;j++){
            a[c[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
