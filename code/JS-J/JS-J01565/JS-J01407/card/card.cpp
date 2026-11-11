#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,m,a[maxn],cnt[maxn];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        int t=i;
        int ohno[maxn];
        memset(ohno,0,sizeof(ohno));
        while(t<=n){
            int wow=1;
            for(int i=1;ohno[i]!=0;i++){
                wow=i;
                if(ohno[i]==a[t]){
                    for(int j=i;ohno[j]!=0;j++)ohno[j]=0;
                    break;
                }
            }
            if(ohno[wow]!=0)ohno[wow+1]=a[t];
            else ohno[wow]=a[t];
            t++;
        }
        for(int i=1;ohno[i]!=0;i++)cnt[ohno[i]]++;
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
    return 0;
}
