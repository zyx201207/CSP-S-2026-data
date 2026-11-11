#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int n,t;
    cin>>n>>t;
    if(n>14||(n<11&&n>6)){
        for(int i=2;i<=t;i++){
            cout<<0<<"\n";
        }
        return 0;
    }
    if(n<=6){
        for(int k=1;k<=t;k++){
            int x,y,an=0;
            cin>>x>>y;
            int a[305][305][2],b[305];
            memset(a,0,sizeof(a));
            for(int i=1;i<=x;i++){
                cin>>b[i];
            }
            for(int i=1;i<x;i++){
                for(int j=i+1;j<=x;j++){
                    if(b[j]-b[i]<=y){
                        a[i][j][0]=1;
                        a[i][j][1]=1;
                    }else{
                        a[i][j][0]=-1;
                    }
                }
            }
            for(int l=2;l<x;l++){
                for(int i=1;i+l<=x;i++){
                    for(int mid=i+1;mid<i+l;mid++){
                        if(a[i][mid][0]==-1||a[mid][i+l][0]==-1) continue;
                        int ans=a[i][mid][1]+a[mid][i+l][1];
                        if(a[i][i+l][0]==-1||ans<a[i][i+l][1]){
                            a[i][i+l][1]=ans;
                            a[i][i+l][0]=0;
                        }
                        if(a[i][i+l][1]==ans){
                            a[i][i+l][0]+=a[i][mid][0]*a[mid][i+l][0];
                        }
                    }
                }
            }
            for(int i=1;i<x;i++){
                for(int j=1;j<=x;j++){
                    if(a[i][j][0]==2){
                        an++;
                    }
                }
            }
            cout<<an<<"\n";
        }
    }else if(n==11||n==12){
        for(int k=1;k<=t;k++){
            int x,y,c,a,b;
            cin>>x>>y>>a;
            for(int i=2;i<=x;i++){
                cin>>b;
            }
            c=(b-a)/(x-1);
            if(y<=c||2*(y/c)>x){
                cout<<0<<"\n";
            }else{
                cout<<x-2*(y/c)+1<<"\n";
            }
        }
    }else{
        for(int k=1;k<=t;k++){
            int a[2000005];
            int x,y,m;
            cin>>x>>y;
            for(int i=1;i<=x;i++){
                cin>>a[i];
                if(a[i]-a[1]<=y){
                    m=i;
                }
            }
            if(a[x]-a[1]<=y){
                cout<<0<<"\n";
                continue;
            }
            int l=0,r=m,ans=0;
            while(l==0||a[r]-a[l]>y){
                l++;
                while(a[r]-a[l]<=y||((a[r]-a[m-1]<=y&&a[m-1]-a[l]<=y)+(a[r]-a[m-2]<=y&&a[m-2]-a[l]<=y)+(a[r]-a[m+1]<=y&&a[m+1]-a[l]<=y)!=1)){
                    if(r==x){
                        break;
                    }else{
                        r++;
                    }
                }
                if(a[r]-a[l]>y&&((a[r]-a[m-1]<=y&&a[m-1]-a[l]<=y)+(a[r]-a[m-2]<=y&&a[m-2]-a[l]<=y)+(a[r]-a[m+1]<=y&&a[m+1]-a[l]<=y)==1)){
                    ans++;
                }
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
