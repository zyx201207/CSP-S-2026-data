#include<bits/stdc++.h>
using namespace std;
int a[500005];
int s[300005];
bool h[300005];//shi fou cun zai
int mm[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int j=1;j<=n;j++){
        int top=0;
        int num=j-1;
        memset(h,0,sizeof(h));
        for(int i=1;i<=n;i++){

            if(i<=num){
                continue;
            }
            if(h[a[i]]){
                while(s[top]!=a[i]){
                    h[s[top]]=0;
                    top--;
                }
                continue;
            }
            ++top;
            s[top]=a[i];
            h[a[i]]=1;
        }
        for(int i=1;i<=top;i++){
            mm[s[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<mm[i]<<" ";
    }
    return 0;
}
