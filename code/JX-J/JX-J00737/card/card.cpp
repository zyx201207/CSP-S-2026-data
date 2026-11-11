#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f,g,s[500010],s1[500010],s2[300010],s3[300010],s4[300010];
bool bo;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&a,&b);
    for(int i=0;i<a;i++){
        scanf("%d",&s[i]);
        s4[s[i]]++;
        if(s4[s[i]]==2)bo=1;
    }
    if(bo==0){
        for(int i=0;i<a;i++){
            s2[s[i]]=i;
        }
        for(int i=1;i<=b;i++){
            printf("%d ",s3[i]);
        }
        return 0;
    }
    for(int j=0;j<a;j++){
        for(int i=j;i<a;i++){
            if(s2[s[i]]==1){
                while(s1[c-1]!=s[i]){
                    c--;
                    s2[s1[c]]--;
                }
            }else{
                s2[s[i]]++,s1[c]=s[i];
                c++;
            }
        }
        for(int z=1;z<=b;z++){
            s3[z]+=s2[z],s2[z]=0;
        }
        for(int z=0;z<c;z++){
            s2[z]=0;
        }
        c=0;
    }
    /*
    for(int i=a-1;i>=0;i--){
        if(s2[s[i]]==1){
            while(s1[c-1]!=s[i]){
                c--;
                s2[s1[c]]--;
            }
        }else{
            s2[s[i]]++,s1[c]=s[i];
            c++;
        }
        for(int j=1;j<=b;j++){
            s3[j]+=s2[j];
        }
    }
    */
    for(int i=1;i<=b;i++){
        printf("%d ",s3[i]);
    }
    return 0;
}
