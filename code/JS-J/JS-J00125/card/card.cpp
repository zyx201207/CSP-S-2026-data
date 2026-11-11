#include<bits/stdc++.h>
using namespace std;
int c[100000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int a[n+1],k=0,l=1;
    for(int i=1;i<=n;i++){ cin>>a[i];
    }
    for(int i=0;i<n;i++){
            int b[n+1],idx=0;
            k=0;
            l=1;
        for(int j=i+1;j<=n;j++){
            if(k==0){
                b[1]=a[j];
                k=1;
            }else{
                if(binary_search(b+1,b+l+1,a[j])){
                    for(int x=1;x<=l;x++){
                        if(b[x]==a[j]){
                            idx=x-1;
                            break;
                        }
                    }
                    if(idx>0)l=idx;
                    else l=1;
                }else{
                b[++l]=a[j];}
            }
        }
        for(int x=1;x<=l;x++){
            c[b[x]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}
