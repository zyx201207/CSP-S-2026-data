#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],m,ans,k[32][200010],s[32],h=1,g,v,hy[32],e[200010],p,y,q,c[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=30;i++)
        h=h*2;
        g=h;
    for(int i=1;i<=n;i++,g=h){
        cin>>a[i];
        v=a[i];
        for(int j=31;g>=1;g=g/2,j--){
                if(v>=g){
                    v=v-g;
                    s[j]++;
                    k[j][s[j]]=i;
                }
        }
    }
    for(int i=31;i>=1;i--,y=0){
        if(s[i]>=m){
            if(p==0){
                q=s[i];
                for(int j=1;j<=q;j++)
                    e[j]=k[i][j];
                    hy[i]=1;
                    p=1;
            }
            if(p!=0){
                for(int j=1;j<=s[i];j++){
                    for(int z=1;z<=q;z++){
                        if(k[i][j]==e[z]){
                            y++;
                            c[y]=e[z];
                        }
                    }
                }
                if(y>=m){
                    hy[i]=1;
                    for(int j=1;j<=y;j++){
                        e[j]=c[j];
                    }
                    q=y;
                }
            }
        }
    }
    for(int i=30;i>=1;i--,h=h/2){
        if(hy[i]==1)
            ans+=h;
    }
    cout<<ans/2;
    return 0;
}
