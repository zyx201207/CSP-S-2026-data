#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
long long ans;
struct str{
    int a;
    char ch;
}s[200010];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        scanf("%d %c\n",&s[i].a,&s[i].ch);
    }
    int l=0,r=a-1,ls=s[l].a,rs=s[r].a;
    while(l<r){
        if(s[l].ch!=s[r].ch){
            if(ls>rs){
                ls-=rs,ans+=rs;
                r--;
                rs=s[r].a;
            }else if(ls<rs){
                rs-=ls,ans+=ls;
                l++;
                ls=s[l].a;
            }else if(ls==rs){
                l++,r--,ans+=ls;
                ls=s[l].a,rs=s[r].a;
            }
        }else{
            if(ls>rs){
                ls-=rs;
                r--;
                rs=s[r].a;
            }else if(ls<rs){
                rs-=ls;
                l++;
                ls=s[l].a;
            }else if(ls==rs){
                l++,r--;
                ls=s[l].a,rs=s[r].a;
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
