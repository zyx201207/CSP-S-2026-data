#include<bits/stdc++.h>
using namespace std;
char c[200005];
long long cnt,cnt1;
long long ans,a[200005],n;

long long i1,i2;
long long a1[100005],a2[100005];
char c1[100005],c2[100005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        cnt=cnt+a[i];
    }
    cnt=cnt/2;
    for(int i=0;i<n;i++){
        i1++;
        cnt1=cnt1+a[i];
        if(cnt1>cnt){
            a1[i]=cnt-cnt1+a[i];
            c1[i]=c[i];
            break;
        }
        a1[i]=a[i];
        c1[i]=c[i];
    }
    //for(int i=0;i<i1;i++)
    //    cout<<a1[i]<<" "<<c1[i]<<endl;



    cnt1=0;

    for(int i=n-1;i>=0;i--){
        i2++;
        cnt1=cnt1+a[i];
        if(cnt1>cnt){
            a2[n-1-i]=cnt-cnt1+a[i];
            c2[n-1-i]=c[i];
            break;
        }
        a2[n-1-i]=a[i];
        c2[n-1-i]=c[i];
    }
    //for(int i=0;i<i2;i++){
    //    cout<<a2[i]<<" "<<c2[i]<<endl;
    //}
    i1=0;
    i2=0;
    while(1){
        if(c1[i1]!=c2[i2]){
            ans=ans+min(a1[i1],a2[i2]);
        }
        a1[i1]=a1[i1]-min(a1[i1],a2[i2]);
        a2[i2]=a2[i2]-min(a1[i1],a2[i2]);
        if(a1[i1]==0){
            i1++;
        }
        if(a2[i2]==0){
            i2++;
        }
        if(a1[i1]==0 or a2[i2]==0){
            break;
        }
    }
    cout<<ans;
    return 0;
}





