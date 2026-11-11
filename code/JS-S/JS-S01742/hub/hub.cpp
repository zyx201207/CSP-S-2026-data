#include<bits/stdc++.h>
using namespace std;
struct node{
    int fa;
    bool xd;
}tre[1000086];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while (t--){
        int n,k;
        tre[1].fa=-1;
        memset(tre,0,sizeof(tre));
        for(int i=0;i<n;i++){
            int l1,l2;
            tre[l2].fa=l1;
        }
        int ans=1e9+10,cnt=0;
        for(int i=0;i<n;i++){
            tre[i].xd=1;
            for(int j=i+1;j<n;j++){
                tre[j].xd=1;
                for(int k=j;k<n;k++){
                    if(tre[k].fa==j){
                        ans++;
                        j=k;
                        break;
                    }
                }
                tre[j].xd=0;
                ans=min(ans,cnt);
            }
            tre[i].xd=0;
            ans=min(ans,cnt);
        }
        cout<<ans<<endl;
    }
    fclose(stdout);
    fclose(stdin);
}
