#include <bits/stdc++.h>
using namespace std;
int a[700001];
bool have[700001],flag=true;
int ans[700001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]<a[i-1])flag=false;
    }
    if(m<=2||flag){
        int s[700001]={0};
        int p=0;
        for(int i=n;i>=1;i--){
            if(!have[a[i]]){
                have[a[i]]=true;
                s[p++]=a[i];
            }
            else{
                while(s[p-1]!=a[i]){
                    have[s[p-1]]=false;
                    p--;
                }
                have[a[i]]=true;
            }
            for(int j=1;j<=m;j++){
                ans[j]+=have[j];
            }
        }
        for(int i=1;i<=m;i++){
            cout<<ans[i]<<' ';
        }
    }
    else{
        for(int skip=0;skip<n;skip++){
            int st[700001]={0};
            int p=0;
            memset(have,false,sizeof have);
            for(int i=skip+1;i<=n;i++){
                if(!have[a[i]]){
                    have[a[i]]=true;
                    st[p++]=a[i];
                }
                else{
                    while(st[p-1]!=a[i]){
                        have[st[p-1]]=false;
                        p--;
                    }
                    have[a[i]]=true;
                }
            }
            for(int i=1;i<=m;i++){
                ans[i]+=have[i];
            }
        }
        for(int i=1;i<=m;i++){
            cout<<ans[i]<<' ';
        }
    }
    return 0;
}
