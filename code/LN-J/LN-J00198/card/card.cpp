#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m,a[100001]={},p[100001]={},s[100001]={},x[100001]={};
    bool f=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int t=1;t<=n;t++){
        for(int i=0;i<=100001;i++){
            p[i]=0;
            s[i]=0;
        }
        for(int i=t;i<=n;i++){
            f=1;
            p[i]=a[i];
            for(int j=1;j<i&&f;j++){
                if(p[j]==p[i]){
                    for(int k=j;k<i;k++){
                        p[k]=0;
                    }
                    f=0;
                }
            }
        }
        for(int i=1;i<=n;i++){
            s[p[i]]=1;
        }
        for(int i=1;i<=m;i++){
            x[i]+=s[i];
        }
    }
    for(int i=1;i<=m;i++){
        cout<<x[i]<<" ";
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
