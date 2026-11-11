#include<bits/stdc++.h>
using namespace std;
int n,m,tmp,a[500005],lst[300005],lsti[500005],ansi[500005],ans[300005];
bool calc[500005];
void workbig(){
    for(int i=n;i>=1;i--){
        if(i<lst[a[i]]){
            for(int j=lst[a[i]];j>=i+1;j--){
                if(!calc[j]);ansi[j]=j-i,lst[a[j]]=lsti[j];
                calc[j]=1;
            }
        }
        lsti[i]=lst[a[i]];
        lst[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        if(!calc[i])ansi[i]=i;
        calc[i]=1;
    }
    for(int i=1;i<=n;i++){
        ans[a[i]]+=ansi[i];
    }
    for(int i=1;i<=m;i++){
        printf("%d ",ans[i]);
    }
}
void work(int lft,int rgt){
    memset(lst,0x3f,sizeof lst);
    memset(lsti,0x3f,sizeof lsti);
    memset(calc,0,sizeof calc);
    for(int i=lft;i<=rgt;i++){
        if(lst[a[i]]<i){
            for(int j=i-1;j>=lst[a[i]];j--){
                calc[j]=1;lst[a[j]]=lsti[j];
            }
        }
        lsti[i]=lst[a[i]];
        lst[a[i]]=i;
    }
    for(int i=lft;i<=rgt;i++){
        if(calc[i]==0)ans[a[i]]++;
    }
}
void worksmall(){
    for(int i=1;i<=n;i++){
        work(i,n);
    }
    for(int i=1;i<=m;i++){
        printf("%d ",ans[i]);
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(n>10000)workbig();
    else worksmall();
    return 0;
}
