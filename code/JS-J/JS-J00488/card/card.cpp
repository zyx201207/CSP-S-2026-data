#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[300010];
bool ru=false;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1]) ru=true;
    }
    if(ru==true){
        for(int i=1;i<=n;i++){
            int c[500010],l=0;
            for(int j=i;j<=n;j++){
                l++;
                c[l]=a[j];
                for(int k=1;k<l;k++){
                    if(c[k]==c[l]){
                        for(int q=k;q<l;q++) c[q]=0;
                        break;
                    }
                }
            }
            for(int j=1;j<=l;j++) ans[c[j]]++;
        }
        for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
        cout<<'\n';
        return 0;
    }
    else{
        int q=0;
        for(int i=1;i<=n;i++){
            q++;
            if(a[i]!=a[i-1]&&i!=1) cout<<q-1<<" ";
        }
        cout<<q<<'\n';
    }
    return 0;
}
