#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],s[500005];
int qq[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            qq[j]=0;
        }
        for(int j=i;j<=n;j++){
            qq[j]=a[j];
            bool flag=0;
            int q=0;
            for(int x=i;x<j;x++){
                if(qq[x]==qq[j]){
                    flag=1;
                    q=x;
                    break;
                }
            }
            if(flag){
                for(int x=q;x<j;x++){
                    qq[x]=0;
                }
            }
        }
        for(int j=1;j<=n;j++){
            s[qq[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<s[i]<<" ";
    }
 return 0;
}
