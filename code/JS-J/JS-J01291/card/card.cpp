#include<bits/stdc++.h>
using namespace std;
int a[500005];
int st[500005],tp=0;
int last[300005],ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            last[j]=0;
        }
        for(int j=i;j<=n;j++){
            if(last[a[j]]!=0){
                while(tp!=0&&a[st[tp]]!=a[j]){
                    tp--;
                    last[a[st[tp]]]=0;
                }
                last[a[j]]=j;
            }else{
                last[a[j]]=j;
                st[++tp]=j;
            }
 //           cout<<tp<<' ';
        }
        while(tp!=0){
            ans[a[st[tp]]]++;
//            cout<<a[st[tp]]<<' ';
            tp--;
        }
 //       cout<<'\n';
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
