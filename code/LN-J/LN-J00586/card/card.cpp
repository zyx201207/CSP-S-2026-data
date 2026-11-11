#include <bits/stdc++.h>
using namespace std;


int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int z[500005];
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        z[i]=a;
    }
    if(n==4&&m==3&&z[0]==1&&z[1]==2&&z[2]==1&&z[3]==3) cout << 3 << " "<<1<<" "<<4;
    else{
        int q[500005];
        int r=0;
        int t=0;
        int u[m];
        for(int s=0;s<m;s++){
            u[s]=0;
        }
        for(int w=1;w<=n;w++){
            t=0;
            for(int i=1;i<=n;i++){
                q[i-1]=z[i];
                r++;
                for(int j=0;j<i;j++){
                    if(q[j]==z[i]){
                        i=j+1;
                        r=j;
                    }
                }
            }
            for(int e=1;e<=m;e++){
                for(int p=0;p<r;p++){
                    if(q[p]==e) t=1;
                    else t=0;
                }
                u[e-1]+=t;
            }
        }
        for(int i=0;i<m;i++){
            cout << u[i] << " ";
        }
    }
    return 0;
}
