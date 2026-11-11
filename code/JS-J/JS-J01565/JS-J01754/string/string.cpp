#include<bits/stdc++.h>
using namespace std;
int a[500010];
char b[500010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        cin>>b[i];
    }
    long long wei=0;
    long long wu1=1;
    long long wu2=n;
    long long ans=0;
    int h=2;
    while(wu1<wu2){
        long long xian1;
        long long xian2;
        if(h==0){
            xian1=wei+a[wu1];
        }
        if(h==1){
            xian2=wei+a[wu2];
        }
        if(h==2){
            xian1=wei+a[wu1];
            xian2=wei+a[wu2];
        }
        if(b[wu1]==b[wu2]){
            if(xian1>xian2){
                wei=xian2;
                wu2-=1;
                h=1;
            }
            if(xian1==xian2){
                wei=xian2;
                wu2-=1;
                wu1+=1;
                h=2;
            }
            if(xian1<xian2){
                wei=xian1;
                wu1+=1;
                h=0;
            }
        }else{
            if(xian1>xian2){
                ans+=xian2-wei;
                wei=xian2;
                wu2-=1;
                h=1;
            }
            if(xian1==xian2){
                ans+=xian2-wei;
                wei=xian2;
                wu2-=1;
                wu1+=1;
                h=2;
            }
            if(xian1<xian2){
                ans+=xian1-wei;
                wei=xian1;
                wu1+=1;
                h=0;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}

