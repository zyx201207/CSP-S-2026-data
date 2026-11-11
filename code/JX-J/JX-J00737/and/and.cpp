#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f,g,cnt,s[200010],s1[33][200010][2],s2[200010],s3[200010],ans;
bool bo;
//shei kan de dong
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&a,&b);
    for(int i=0;i<a;i++){
        scanf("%d",&s[i]);
        d=0,c=s[i];
        while(c){
            if(c&1==1){
                int qwq=s1[d][0][0];
                if(s1[d][qwq][0]==s[i])s1[d][qwq][1]++;
                else qwq++,s1[d][0][0]++,s1[d][qwq][0]=s[i],s1[d][qwq][1]=1;
            }
            c=c>>1,d++;
        }
    }
    for(int i=30;i>=0;i--){
        if(s1[i][0][0]>=b){
            if(bo==0){
                for(int j=1;j<=s1[i][0][0];j++){
                    s2[cnt]=s1[i][j][0],cnt+=s1[i][j][1];
                    //printf("%d ",s2[cnt-1]);
                }
                bo=1;
            }
            g=0;
            for(int x=1;x<=s1[i][0][0];x++){
                for(int j=0;j<cnt;j++){
                    //printf("%d he %d\n",s1[i][x][0],s2[j]);
                    if(s1[i][x][0]==s2[j]){
                        s3[g]=s2[j],g+=s1[i][x][1];
                        //printf("%d ",s3[g-1]);
                        break;
                    }
                }
            }
        }
        //printf("\ng=%d\n",g);
        if(g>=b){
            cnt=g;
            for(int j=0;j<g;j++)s2[j]=s3[j];
        }
        if(cnt==b)break;
    }
    //printf("%d\n",cnt);
    ans=s2[0];
    for(int j=1;j<cnt;j++){
        ans=ans&s2[j];
        //printf("%d\n",s2[j]);
    }
    printf("%d",ans);
    return 0;
}
