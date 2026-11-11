#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[500005],t[300005];
int js[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
            int ans=0;
        for(int j=i;j<=n;j++){
            ans++;
            b[ans]=a[j];
            t[b[ans]]++;
            if(t[b[ans]]>1){
                for(int k=1;k<=ans;k++){
                    if(b[k]==b[ans]){
                        for(int p=k+1;p<=ans;p++){
                            t[b[p]]--;
                            b[p]=0;
                        }
                        ans=k;
                        break;
                    }
                }
            }
        }
        for(int q=1;q<=m;q++){
            if(t[q]>0){
                js[q]++;
                t[q]=0;
                continue;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<js[i]<<" ";
    }
    return 0;
}
