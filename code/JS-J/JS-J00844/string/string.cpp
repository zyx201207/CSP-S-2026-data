#include<bits/stdc++.h>
using namespace std;
long long a[26],d[26];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long sp=0,sum=0,sum1=0,sum2=0,ans=0;
    int b[200001];cin>>n;
    char c[200001];
    for(int i=1;i<=n;i++){
        cin>>b[i]>>c[i];
        sum+=b[i];
    }
    if(sum/2*2!=sum) sp=sum/2+1;
    int t=0;
    while(sum1<sum/2+1){
        t++;
        sum1+=b[t];
        a[c[t]-'a']+=b[t];
    }
    if(sum1>sum/2){
        a[c[t]-'a']=a[c[t]-'a']-(sum1-sum/2);
        sum2+=(sum1-sum/2);
        d[c[t]-'a']=d[c[t]-'a']+(sum1-sum/2);
    }
    t++;
    sum2+=b[t];
    d[c[t]-'a']+=b[t];
    if(sp!=0){
        sum2--;
        d[c[t]-'a']--;
    }
    while(sum2<sum/2){
        t++;
        sum2+=b[t];
        d[c[t]-'a']+=b[t];
    }
    for(int i=0;i<26;i++)ans+=abs(a[i]-d[i]);
    cout<<ans/2<<endl;
    return 0;
}
