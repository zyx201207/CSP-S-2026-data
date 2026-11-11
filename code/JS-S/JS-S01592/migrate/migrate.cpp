#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,p[2000001],k[2000001],ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans=0;
        memset(p,0,sizeof p);
        memset(k,0,sizeof k);
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>k[i];
            if(i>1)p[i]=p[i-1]+(k[i]-k[i-1]);
        }
        /*for(int i=1;i<=n;i++){
            cout<<p[i]<<' ';
        }
        cout<<endl;*/
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){/*
                if(p[i]-p[j]>d&&(p[i]-p[j])%d!=0){
                    bool flag=true;
                    for(int k=j+1;k<=i;k++){
                        if(p[k]-p[k-1]>d){
                            flag=false;
                            cout<<p[k]<<' '<<p[k-1]<<endl;
                        }
                        break;
                    }
                    if(flag==false){
                        continue;
                    }
                    int aa=(p[i]-p[j])/d;
                    if((p[i]-p[j])%d!=0)aa++;
                    if(aa==2){
                        ans++;
                    }
                }*/
                if(p[i]-p[j]>d&&p[i]-p[j]<2*d){
                    bool flag=true;
                    for(int k=j+1;k<=i;k++){
                        if(p[k]-p[k-1]>d){
                            flag=false;
                            //cout<<p[k]<<' '<<p[k-1]<<endl;
                        }
                        break;
                    }
                    if(flag==false){
                        continue;
                    }
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
