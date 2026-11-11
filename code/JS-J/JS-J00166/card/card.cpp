#include<bits/stdc++.h>
using namespace std;
int c[500100]={0};
int t[500100]={0};
int ans[500100]={0};
bool f;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    int k,l,kp;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            t[j]=0;
        l=1;
        for(int j=i;j<=n;j++){
            k=c[j];
            f=0;
            for(int a=1;a<=l;a++){
                if(t[a]==k){
                    f=1;
                    kp=a;
                }
            }
            if(f){
                for(int a=kp;a<=l;a++){
                    t[a]=0;
                    l--;
                }
            }
            t[++l]=k;
        }
        for(int num=1;num<=m;num++){
            for(int j=1;j<=l;j++){
                if(t[j]==num){
                    ans[num]++;
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
