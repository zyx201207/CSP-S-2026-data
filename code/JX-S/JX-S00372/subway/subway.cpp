#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[125265],b[125265][515];
int t[125265];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    int k;
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k*2;j++){
            cin>>b[j][i]>>t[j];
        }
    }
    int jiao[515]={0},t=0;
    for(int i=1;i<n;i++){
        for(int j=1;j<=k*2;j++){
            if(b[j][i]==b[j][i+1]) jiao[++t]=j;
        }
    }
    for(int i=1;i<=q;i++){
        int be,l;
        cin>>be>>l;
        int sum=0;
        for(int i=1;i<=n;i++){
			bool f=0;
            for(int j=1;j<=k*2;j++){
                if(b[j][i]==be){
                     sum+=a[j];
                     for(int f=j;f<=jiao[j];f++){
                        sum+=a[f]*2;
                     }
                     sum+=a[jiao[j]];
                     for(int f=jiao[j];f<=b[j+1][l];f++){
                        sum+=a[f]*2;
                     }
                     sum+=a[l];
                     f=1;
                     break;
                }
            }
            if(f) break;
        }
        cout<<sum<<endl;
    }
    return 0;
}
