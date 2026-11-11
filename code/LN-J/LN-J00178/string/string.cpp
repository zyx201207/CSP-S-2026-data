#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=2e5+5;
int n,x,t,a1[30],a2[30],ans01,max01=-1,max02=-1,max03=0;
char y,ans[maxn],max11,max22;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
       scanf("%d %c",&x,&y);
       for(int j=1+t;j<=1+t+x;j++) ans[j]=y;
       t+=x;
    }
    //for(int i=1;i<=t;i++) cout<<ans[i]<<" ";
    //cout<<endl;
    for(int i=1;i<=t/2;i++){
        a1[ans[i]-'a']++;
        if(a1[ans[i]-'a']>max01){
            max01=a1[ans[i]-'a'];
            max11=ans[i];
        }
    }
    for(int i=(t+1)/2+1;i<=t;i++){
        a2[ans[i]-'a']++;
        if(a2[ans[i]-'a']>max02){
            max02=a2[ans[i]-'a'];
            max22=ans[i];
        }
    }
    ans01=0;
    for(int i=1;i<=t/2;i++){
        if(ans[i]==max22) ans01++;
    }
    max03=t-ans01-max02-(t%2);
    //cout<<ans01<<endl;
    ans01=0;
    for(int i=(t+1)/2+1;i<=t;i++){
        if(ans[i]==max11) ans01++;
    }
    max03=min(t-ans01-max01,max03-(t%2));
    max03=max(max03,0);
    //cout<<ans01<<endl;
    //cout<<max01<<" "<<max11<<" "<<max02<<" "<<max22<<endl;
    printf("%d",max03);
    return 0;
}
