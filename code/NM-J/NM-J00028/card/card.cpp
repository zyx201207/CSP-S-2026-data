#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int h[1000100],k[1000100],ans[400010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int j=1;j<=n;j++){
            cin>>h[j];
        }
    for(int i=1;i<=n;i++){
        k[i]=h[i];
    }
    for(int i=1;i<=n;i++){
            if(h[i]==0) continue;
        for(int a=i;a<=n;a++){
            if(h[i]==h[a]){
                for(int p=i;i<=a;i++){
                    h[p]=0;
                }
            }
        }
       for(int f=1;f<=n;f++){
            for(int y=1;y<m;y++){
                if(h[y]==0)continue;
                else {
                    sort(h+1,h+m+1)
                    if(h[y]==h[y+1]) ans[y]++;
                    else ans[y+1]++;
            }
       }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i];
    }

    return 0;
}

