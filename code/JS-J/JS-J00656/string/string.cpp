#include<bits/stdc++.h>
using namespace std;
struct node{
    long long x;
    char s;
    long long tnt;
}str[1000010];
long long ret=0;
void ch(int a,int b){
    if(str[a].x>=str[b].x){
        str[b-1].tnt=str[a].x-str[b].x;
        ret+=str[b].x;
    }else{
        str[a+1].tnt=str[b].x-str[a].x;
        ret+=str[a].x;
    }
}
void dh(int a,int b){
    if(str[a].x>=str[b].x){
        str[b-1].tnt=str[a].x-str[b].x;
        ret+=str[b-1].tnt;
    }else{
        str[a+1].tnt=str[b].x-str[a].x;
        ret+=str[a+1].tnt;
    }
}
int main(){
//    freopen("string.in","r",stdin);
//    freopen("string.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%s",&str[i].x,&str[i].s);
    }
    for(int i=1;i<=n;i++){
        if(str[i].s!=str[n+1-i].s){
            ch(i,n-i+1);
        }else{
            str[i].x-=str[i].tnt;
            str[n-i+1].x-=str[n-i+1].tnt;
            dh(i,n-i+1);
        }
    }
    printf("%d\n",ret/2);
    return 0;
}
