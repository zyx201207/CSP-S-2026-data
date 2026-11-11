#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int c[300010];
int la[300010];
bool nm=1;
int an[300010];
set<int> s[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]<a[i-1]) nm=0;
    }
    if(nm){
        for(int i=n;i>=1;i--){
            if(c[a[i]]==0) an[a[i]]+=i;
            c[a[i]]=1;
        }
        for(int i=1;i<=m;i++) printf("%d ",an[i]);
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            s[j].clear();
        }
        for(int j=1;j<=m;j++) {
            la[j]=0;
        }
        for(int j=i;j<=n;j++){
            int x=a[j];
            if(la[x]){
                s[j]=s[la[x]];
                for(int k=la[x];k<j;k++) la[a[k]]=0;
                la[x]=j;
            }else{
                s[j]=s[j-1];
                s[j].insert(x);
                la[x]=j;
            }
        }
        for(auto j=s[n].begin();j!=s[n].end();j++){
            an[*j]++;
        }
    }
    for(int i=1;i<=m;i++) printf("%d ",an[i]);
    return 0;
}
