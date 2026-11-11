#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int c,T;
int main(){
    cin>>c>>T;
    while(T--){
        int n,d;
        int x[2000006];
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        if(c<=6){
            int a=0;
            int f[305][305],cnt[305][305];
            memset(f,inf,sizeof(f));
            memset(cnt,0,sizeof(cnt));
            for(int k=1;k<=n;k++){
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=n;j++){
                        if(i==j){
                            f[i][j]=0;
                            cnt[i][j]=1;
                        }else if(abs(x[i]-x[j])<=d){
                            f[i][j]=1;
                            f[j][i]=1;
                            cnt[i][j]=1;
                        }else{
                            int s=f[i][k]+f[k][j];
                            if(s==f[i][j])cnt[i][j]++;
                            else if(s<f[i][j]){
                                f[i][j]=s;
                                cnt[i][j]=1;
                            }
                        }
                    }
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    if(cnt[i][j]==2){
                        c++;
                    }
                }
            }
            cout<<c<<endl;
        }
    }
    return 0;
}
