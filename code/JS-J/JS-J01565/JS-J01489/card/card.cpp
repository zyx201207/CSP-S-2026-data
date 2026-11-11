#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[5005],ans[3005],vis[3005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof vis);
        string s="";
        for(int j=i;j<=n;j++){
            if(vis[a[j]]==0){
                s+=to_string(a[j]);
                vis[a[j]]+=1;
            }else{
                int pos=s.find(to_string(a[j]));
                for(int z=pos+1;z<j;z++)vis[a[z]]-=1;
                s.erase(pos,s.size()-pos);
                s+=to_string(a[j]);
            }
        }
        for(int j=0;j<s.size();j++)ans[int(s[j]-'0')]++;
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
