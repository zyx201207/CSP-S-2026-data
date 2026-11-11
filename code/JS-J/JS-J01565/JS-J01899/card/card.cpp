#include<bits/stdc++.h>
using namespace std;
int a[500010];
int b[500010];
int cnt[300010];
int ans[300010];
int main()
{
    memset(ans,0,sizeof(ans));
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,l;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int j=1;
        memset(cnt,0,sizeof(cnt));
        memset(b,0,sizeof(b));        
        for(int next=i;next<=n;next++){
            if(cnt[a[next]]==0){
                b[j]=a[next];
                cnt[a[next]]=j;
                j++;
            }
            else {
                l=j;
                for(int k=cnt[a[next]];k<l;k++){
                    b[k]=0;
                    cnt[b[k]]=0;
                    j--;
                }
                b[j]=a[next];
                cnt[a[next]]=j;
                j++;
            }
    

        }
        for(int p=1;p<=n;p++){
            ans[b[p]]++;
        };
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;




}