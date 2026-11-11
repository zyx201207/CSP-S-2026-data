#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,f[5005][5005],s[5005],cnt[5005][5005],js;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        js=0;
        memset(f,0x3f,sizeof(f));
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++){
            cin>>s[i];
            f[i][i]=0;
            if(s[i]-s[i-1]<=d&&i>1)f[i-1][i]=1;
        }
        for(int len=3;len<=n;len++){
            for(int l=1;l<=n-len+1;l++){
                int r=l+len-1;
                if(s[r]-s[l]<=d)f[l][r]=1;
                for(int k=l;k<=r;k++){
                    if(f[l][k]!=0&&f[k][r]!=0&&f[k]-f[l]>d&&f[r]-f[k]>d){
                        f[l][r]=min(f[l][r],f[l][k]+f[k][r]);
                    }
                    else if(f[l][k]!=0&&f[k][r]!=0&&f[k]-f[l]<=d&&f[r]-f[k]>d){
                        f[l][r]=min(f[l][r],1+f[k][r]);
                    }
                    else if(f[l][k]!=0&&f[k][r]!=0&&f[k]-f[l]>d&&f[r]-f[k]<=d){
                        f[l][r]=min(f[l][r],f[l][k]+1);
                    }
                    else{
                        if(f[l][k]!=0&&f[k][r]!=0){
                            f[l][r]=2;
                        }
                    }
                }
                for(int k=l;k<=r;k++){
                    if(f[l][k]!=0&&f[k][r]!=0&&f[k]-f[l]>d&&f[r]-f[k]>d){
                        if(f[l][r]==f[l][k]+f[k][r]&&f[l][r]!=0x3f&&f[l][r]!=1)cnt[l][r]++;
                    }
                    else if(f[l][k]!=0&&f[k][r]!=0&&f[k]-f[l]<=d&&f[r]-f[k]>d){
                        if(f[l][r]==1+f[k][r]&&f[l][r]!=0x3f&&f[l][r]!=1)cnt[l][r]++;
                    }
                    else if(f[l][k]!=0&&f[k][r]!=0&&f[k]-f[l]>d&&f[r]-f[k]<=d){
                        if(f[l][r]==f[l][k]+1&&f[l][r]!=0x3f&&f[l][r]!=1)cnt[l][r]++;
                    }
                    else{
                        if(f[l][k]!=0&&f[k][r]!=0&&f[l][r]!=0x3f&&f[l][r]!=1){
                            cnt[l][r]++;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(cnt[i][j]==2)js++;
            }
        }
        cout<<js<<endl;
    }
return 0;
}
