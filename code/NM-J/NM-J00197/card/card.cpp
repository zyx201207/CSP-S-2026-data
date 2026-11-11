#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,;
    cin>>n,m;
    int b[n];
    int c[n];
    int ans[m],cnt[m];
    for(int i=0;i<n;i++){
        cin>>b[i];
        c[i]=b[i];
    }
    int x=1;
    while(n--){
        for(int i=0;i<n;i++){
            c[i]=b[i];
        }
        for(int i=x-1;i<m;i++){
            int p=m;
            while(p--){
                cnt[c[i]]++;
                for(int j=0;j<m;j++){
                    if(cnt[j]>1){
                        int v=cnt[j];
                        for(int t=0;t<m;t++){
                            if(c[t]==v){
                                c[t]=0;
                                if(c[t+1]==v){
                                    break;
                                }
                            }
                        }
                    }
                }
                for(int f=0;f<n;f++){
                    b[f]=c[f];
                    c[f]=0;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        if(b[i]!=0){
            cout<<b[i]<<" ";
        }
    }
    return 0;
}
