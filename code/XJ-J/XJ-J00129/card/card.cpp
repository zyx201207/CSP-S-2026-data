#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int b[100001];
    int a[100001];
    int sc[100001];
    for(int i=0;i<n;i++){
        cin>>a[i];
        sc[i]=a[i];
    }
    for(int x=0;x<n;x++){
        for(int i=x;i<=n;i++){
            for(int j=0;j<i;j++){
                if(a[j]==a[i]){
                    for(int q=j;q<i;q++){
                        a[q]=0;
                    }
                }
            }
        }
        for(int j=1;j<=n;j++){
            if(a[j]!=0){
                b[a[j]]+=1;
            }
        }
        for(int i=x;i<=n;i++){
            a[i]=sc[i];
        }
    }
    for(int i=1;i<=n;i++){
        if(b[i]!=0) cout<<b[i]<<" ";
    }
    return 0;
}
