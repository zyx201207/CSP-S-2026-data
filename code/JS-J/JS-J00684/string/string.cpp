#include<bits/stdc++.h>
using namespace std;
long long zi[599]={0};
long long an=0;
int str[255555]={0};
int sum[255555]={0};
long long ans=0;
string s="";
int num=0;
int maxa=0;
int main(){
     freopen("string.in","r",stdin);
     freopen("string.out","w",stdout);
int n;cin>>n;
for(int i=1;i<=n;i++){
    int a;cin>>a;char c;cin>>c;
    zi[c]+=a;an+=a;
str[i]=c;sum[i]=a;
   // while(a--)s+=c;

}
for(int i='a';i<='z';i++){
    if(zi[i])num++;
    //cout<<i<<" "<<zi[i]<<endl;
   if(zi[i]>maxa){
        maxa=zi[i];//f=i;
}

}
//cout<<maxa<<" "<<ans/2-maxa<<" "<<ans;
//sort(zi,zi+200);
if(n==1){
    cout<<0;return 0;
}
if(n==2){
    if(num==1){
        cout<<0;return 0;
    }
    else {
            cout<<an-maxa;return 0;
    }
}

for(int i=1;i<=n;i++){
    if(str[i]!=str[n+1-i]){
        ans+=min(sum[i],sum[n+1-i]);
    }
    else ans+=abs(sum[i]-sum[n+1-i]);
}
cout<<ans<<endl;

    return 0;
}
//3 2 a 2 b 1 c

