#include<bits/stdc++.h>
using namespace std;
int n,tn=0,ti,l,r;
char c[200001],lfc[200001],rtc[200001];
long long a[200001],sum=0,lf[200001],rt[200001];
string s1,s2;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        char ch;
        cin>>x>>ch;
        sum+=x;

        if(i!=1&&ch==c[i-1-tn]){
            a[i-1-tn]+=x;
            tn++;
        }
        else{
            a[i-tn]=x;
            c[i-tn]=ch;
        }
    }
    n=n-tn;
    sum=sum/2+sum%2;
    long long xx=0;
    for(int i=1;i<=n;i++){
        xx+=a[i];
        if(xx>=sum){
            ti=i;
            break;
        }
    }
    if(xx-sum!=0){
        lf[1]=a[ti]-xx+sum;
        lfc[1]=c[ti];
        for(int i=2;i<=ti;i++){
            lf[i]=a[ti-i+1];
            lfc[i]=c[ti-i+1];
        }
        l=ti;
    }
    else{
        lf[1]=a[ti];
        lfc[1]=c[ti];
        for(int i=2;i<=ti;i++){
            lf[i]=a[ti-i];
            lfc[i]=c[ti-i];
        }
        l=ti;
    }
    if(sum==xx){
        rt[1]=a[ti+1];
        rtc[1]=c[ti+1];
        for(int i=2;i<=n-ti;i++){
            rt[i]=a[ti+i];
            rtc[i]=a[ti+i];
        }
        r=n-ti;
    }
    else{
        rt[1]=a[ti]-lf[1];
        rtc[1]=c[ti];
        for(int i=2;i<=n-ti+1;i++){
            rt[i]=a[ti+i-1];
            rtc[i]=c[ti+i-1];
        }
        r=n-ti+1;
    }
    for(int i=1;i<=l;i++){
        for(int j=1;j<=lf[i];j++){
            s1+=lfc[i];
        }
    }
     for(int i=1;i<=r;i++){
        for(int j=1;j<=rt[i];j++){
            s2+=rtc[i];
        }
    }
    long long ans=0;
    for(int i=1;i<s1.size();i++){
        if(s1[i]!=s2[i])ans++;
    }
    cout<<ans<<"\n";
    return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
