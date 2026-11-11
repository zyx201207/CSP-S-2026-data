#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d,x[2000007],ans,track[2000007];
void finds(int a,int b){
    for(int i=0;i<=n;i++){
        track[i]=0;
    }
    track[1]=a;
    int p=2;
    for(int i=a;i<=b;i++){
        if(x[b]-x[a]<=d){
            track[p]=b;
            return ;
        }
        else if(x[i+1]-x[a]>d){
            track[p]=i;
            p++;
            a=i;
            continue;
        }
        else if(x[i+1]-x[i]>d){
            break;
        }
    }


}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>x[j];
        }
        long long dis;
        for(long A=1;A<n;A++){
            for(long B=A+1;B<=n;B++){
                finds(A,B);
                for(int i=1;i<=n;i++){
                        if(track[i]!=0){
                            cout<<track[i]<<" ";
                        }
                }
                cout<<'\n';
            }
        }
        cout<<ans<<'\n';
        ans=0;
    }

    return 0;
}
