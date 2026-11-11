#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    if(n<=3){

        int a[999],t[5][9990],l[5][999];
        for(int i=1;i<=m;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            int k;
            cin>>k;
            for(int j=1;j<=k;j++){
                cin>>l[i][j]>>t[i][j];
            }
        }
        for(int i=1;i<=q;i++){
            int x,y;
            cin>>x>>y;
            int ans=999999;
            int s1,s2,f1,f2;
            bool lest=0;
            for(int j=1;j<=n;j++){
                for(int k=1;k<=30;k++){
                    if(l[j][k]==x){
                        s1=j,s2=k;
                    }
                    if(l[j][k]==y && j==s1){
                        f1=j,f2=k;
                        lest=1;
                    }
                    if(l[j][k]==y && lest==0){
                        f1=j,f2=k;
                    }
                }
            }

            if(s1==f1){
                ans=a[x]+a[y]+t[s1][s2]+t[f1][f2];;
                cout<<ans<<endl;
                continue;
            }

            for(int j=1;j<=99;j++){
                for(int k=1;k<=99;k++){
                    if(l[s1][j]!=0 || l[f1][k]!=0){
                        if(l[s1][j]==l[f1][k]){
                            ans=min(ans,(a[x]+a[y]+t[s1][s2]+t[f1][f2]+t[s1][j]+t[f1][k]));
                        }
                    }
                }
            }
            cout<<ans<<endl;

        }

    }
}
