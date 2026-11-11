#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int se[M];
int a[N],b[N],c[N],s[N];
int flag[M];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,cnt=0,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=i;
    }
    for(int i=1;i<=n;i++){
        memset(flag,0,sizeof(flag));
        for(int j=i;j<=n;j++){
            if(se[a[j]]==0)se[a[j]]=j;
            else if(se[a[j]]!=0&&flag[se[a[j]]]==0){
                for(int k=se[a[j]];k<j;k++){
                    flag[k]=1;
                }
                se[a[j]]=j;
            }
            else{
                se[a[j]]=j;
            }
        }
        for(int j=i;j<=n;j++){
            if(flag[j]==0)s[a[j]]+=1;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<s[i]<<" ";
    }
    return 0;
}
