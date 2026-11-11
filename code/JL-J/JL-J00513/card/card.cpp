#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],ans[N],ans2[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m,x;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int i=n-1;i>=0;i--){
        int flagi=n-i;
        for(int j=n-i;j<=n;j++){
            int flag=0;
            for(int k=flagi;k<j;k++){
                if(a[j]==a[k]){
                    flag=1;
                    flagi=j-1;
                }
            }
            if(flag==0){
                ans2[a[j]]=1;
            }else{
                for(int p=flagi;p<j;p++){
                    ans2[a[p]]=0;
                }
                ans2[a[j]]=1;
            }
        }
        for(int i=1;i<=m;i++){
            ans[i]=ans[i]+ans2[i];
            ans2[i]=0;
        }
    }
    for(int i=1;i<=m;i++){
    }

    return 0;
}
