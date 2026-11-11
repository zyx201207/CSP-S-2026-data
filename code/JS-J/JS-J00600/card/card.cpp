#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[500005],cnt[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(n<=500){
        for(int k=1;k<=n;k++){
            int b[500005]={},l;
            for(int i=k;i<=n;i++){
                bool f=0;
                int p=0;
                for(int j=l;j>=1;j--)
                    if(a[i]==b[j]){
                        f=1;
                        p=j;
                        break;
                    }
                if(f){
                    l=p-1;
                }
                b[++l]=a[i];
            }
            int f[300005]={};
            for(int i=1;i<=l;i++){
                f[b[i]]=1;
            }
            for(int i=1;i<=m;i++)cnt[i]+=f[i];
        }
        for(int i=1;i<=m;i++)printf("%d ",cnt[i]);
    }else{
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            if(i==n||a[i+1]>a[i]){
                cnt[a[i]]=i;
            }
        }
        for(int i=1;i<=m;i++)printf("%d ",cnt[i]);
    }
    return 0;
}
