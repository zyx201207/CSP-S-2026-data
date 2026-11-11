#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500001],pos[300001],ans[300001];
string cnt;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        cnt.clear();
        fill(pos+1,pos+m+1,0);
        for(int j=i;j<=n;j++){
            if(!pos[a[j]]){
                cnt+=(a[j]+'0');
                pos[a[j]]=cnt.size();
            }else{
                for(int k=pos[a[j]]-1;k<cnt.size();k++)
                    pos[cnt[k]-'0']=0;
                cnt=cnt.substr(0,pos[a[j]]-1);
                cnt+=(a[j]+'0');
                pos[a[j]]=cnt.size();
            }
        }
        for(int j=1;j<=m;j++)
            if(pos[j]) ans[j]++;
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<" ";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
