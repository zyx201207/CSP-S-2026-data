#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],d[500005],ans[300005];
void game(int c[],int b[],int i){
    int len=n;
    for(int j=i;j<=n;j++){
        bool die=0;
        for(int k=1;k<=n;k++){
            if(die){
                c[k]=0;
                continue;
            }
            if(c[k]==b[j]){
                die=1;
                c[k]=0;
                len=k-1;
                continue;
            }
        }
        len++;
        c[len]=b[j];
        for(int i=1;i<=len;i++){
            //cout<<c[i]<<" ";
        }
        //cout<<endl;
    }
    bool is[300005]={0};
    for(int i=1;i<=len;i++){
        is[a[i]]=1;
    }
    for(int i=1;i<=len;i++){
        ans[i]+=is[i];
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        d[i]=a[i];
    }
    for(int i=1;i<=n;i++){
        game(a,d,i);
    }
    for(int i=1;i<=m;i++){
        cout<<n<<" ";
    }
    return 0;
}
