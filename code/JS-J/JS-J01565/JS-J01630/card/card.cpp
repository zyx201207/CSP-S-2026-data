#include<bits/stdc++.h>
using namespace std;

int n,m,a[500005],s[500005],b[500005];

int main(){
    freopen("card.in","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int c=1;c<=n;c++){
        int f[m+1]={0};
        for(int i=c;i<=n;i++){
            b[i]=a[i];
            if(f[a[i]]>=1)
                for(int j=c;j<i;j++)
                    if(b[j]==a[i]){
                        for(int k=j;k<i;k++){
                            f[a[k]]--;
                            b[k]=0;
                        }
                        break;
                    }
            f[a[i]]++;
        }
        for(int i=1;i<=m;i++) if(f[i]>=1) s[i]++;
    }
    for(int i=1;i<=m;i++) cout<<s[i]<<" ";
    freopen("card.out","w",stdout);
    return 0;
}
