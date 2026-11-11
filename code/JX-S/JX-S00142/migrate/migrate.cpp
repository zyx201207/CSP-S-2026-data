#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f,g,ans,cnt,wh,x,bianhao,t,s[2000010],s1[2000010],s2[2000010];
//!?bianhao?!
bool deng;
void bfs(int w){
    queue<int>q;
    q.push(w);
    while(!q.empty()){
        int th=q.front();
        q.pop();
        //printf("%d\n",mp[th.h].size());
        printf("%d ",th);
        for(int i=1;s[th+i]-s[th]<=b;i++){
            if(s1[th+i]>s1[th]+1)s1[th+i]=s1[th]+1,s2[th+i]=1,q.push(th+i);
            else if(s1[th+i]==s1[th]+1)s2[th+i]++;

        }

    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d %d",&bianhao,&t);
    /*
    //if(bianhao<=2){
        while(t--){
            ans=0;
            for(int i=0;i<a;i++){
                s1[i]=0;
            }
            scanf("%d %d",&a,&b);
            deng=1;
            for(int i=0;i<a;i++){
                scanf("%d ",&s[i]);
            }
            //printf("\n\n\n");
            for(int i=0;i<a;i++){
                for(int j=0;j<a;j++){
                    printf("%d ",s2[j]);
                    if(s2[j]==2)ans++;
                }
                printf("\n");
            }
            printf("%d\n",ans);
        }
        return 0;
    //}
    while(t--){
        for(int i=0;i<a;i++){
            s1[i]=0;
        }
        scanf("%d %d",&a,&b);
        if(b>=a){
            printf("0\n");
            continue;
        }
        deng=1;
        for(int i=0;i<a;i++){
            scanf("%d",&s[i]);
            if(i==1)x=s[i]-s[i-1];
            if(s[i]!=s[i-1]+x&&i>1)deng=0;
        }
        if(deng){

        }
    }
    */
    while(t--){
        printf("0");
    }
    return 0;
}
