#include<bits/stdc++.h>
using namespace std;
int n;
long long ans=0,len=0;
struct informations{
    int a;
    char c;
}s[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].c;
        len+=s[i].a;
    }
    int cmark1=s[1].a,cmark2=s[n].a,markposl=1,markposr=n,lastmin=0;
    while(markposl<markposr){
        if(cmark1==0){
            markposl++;
            cmark1=s[markposl].a;
        }
        if(cmark2==0){
            markposr--;
            cmark2=s[markposr].a;
        }
        if(markposl>markposr) break;
        lastmin=min(cmark1,cmark2);
        if(s[markposl].c!=s[markposr].c){
            ans+=lastmin;
        }
        cmark1-=lastmin;
        cmark2-=lastmin;
    }
    printf("%lld",ans);
    return 0;
}
