#include<bits/stdc++.h>
using namespace std;
int a[200005][2];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long ai;
    char ci;
    cin>>n;
    int l=1,r=n;
    long long ans=0;
    for (int i=1;i<=n;i++){
        cin>>ai>>ci;
        a[i][0]=ai;
        a[i][1]=int(ci);
    }
    if (n==1) cout<<0;
    else{
        while(r-l>1){
            if(a[l][1]==a[r][1]){
                if(a[l][0]==a[r][0]){
                    l+=1;
                    r-=1;
                }
                else if(a[l][0]>a[r][0]){
                    a[l][0]-=a[r][0];
                    r-=1;
                }
                else{
                    a[r][0]-=(a[l][0]);
                    l+=1;
                }
            }

            else{
                if(a[l][0]==a[r][0]){
                    ans+=a[l][0];
                    l+=1;
                    r-=1;
                }
                else if(a[l][0]>a[r][0]){
                    ans+=a[r][0];
                    a[l][0]-=(a[r][0]);
                    r-=1;

                }
                else{
                    ans+=a[l][0];
                    a[r][0]-=(a[l][0]);
                    l+=1;
                }
            }
            if(r-l==1 && a[l][1]!=a[r][1]) ans+=min(a[l][0],a[r][0]);

        }
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;

}
