#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

long long m,n,ans=0,a[500005],l,an,ap=0,app=0,vis[500005],cnt[500005],p[500005];

int main(){
    freopen("card.in",'r',stdin);
    freopen("card.out",'w',stdout);
    cin>>m>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int i = 1;i<=n;i++){

        for(int j = i;j<=n;j++){
            if(vis[a[j]]==0){
                vis[a[j]]=1;
            }
            if(vis[a[j]]>0){
                for(int k = 1;k<=j;k++){
                    if(a[j]==a[k]){
                        for(int s = k;s<=j;s++){
                            a[s]=0;
                        }
                    }
                }
            }
        }
        for(int j = 1;j<=n;j++){
            if(a[j]!=0){
                cnt[a[j]]=1;
            }
        }
    }
    return 0;
}
