#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int>a(n+5),s(m+5),p(n+5);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        p[i]=i;
        for(int j=i-1;j>0;j--){
            if(a[j]==a[i]){
                p[i]=j;
                break;
            }
        }

    }
        vector<int>st(n+5);
    for(int i=1;i<=n;i++){
        for(int t=0;t<n+5;t++){
            st[t]=0;
        }
        for(int j=i;j<=n;j++){
            if(p[j]>=i&&st[p[j]]!=0){
                for(int t=j-1;t>=p[j];t--){
                      //  cout<<t<<" ";
                    st[t]=0;
                }
            }
           // cout<<"\n";
            st[j]=a[j];
        }
        for(int i=1;i<=n;i++){
              //  cout<<st[i]<<" ";
            s[st[i]]++;
        }//cout<<"\n";
    }
    for(int i=1;i<=m;i++){
        cout<<s[i]<<" ";
    }
    return 0;
}
//10 3 3 1 2 1 3 2 3 1 2 1
