#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ma=0;
    int b[200010];
    for(int i=0;i<m+1;i++)b[i]=0;
    while(b[m]==0){
        b[0]++;
        for(int i=0;i<m;i++){
            if(b[i]>=n){
                b[i]=0;
                b[i+1]++;
            }
        }
        int asd=0;
        int cc[n];for(int i=0;i<n+1;i++)cc[n]=0;
        for(int i=0;i<n;i++){
            if(cc[i]==1){
                asd=1;
                cout<<1;
                break;
            }
            if(cc[i]==0){
                cc[i]=1;
            }
        }
        if(asd==0){
            int ans=a[b[0]];
        for(int i=1;i<m;i++){
            ans=ans & a[b[i]];
        }
        if(ans>ma){
            ma=ans;
        }
        }


    }
    cout<<ma-3;
    return 0;
}
