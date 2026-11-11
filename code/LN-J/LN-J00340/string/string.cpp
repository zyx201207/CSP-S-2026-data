#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200001],ans;
char c[200001];
long long abss(long long x){
    if(x>=0)return x;
    else return -x;
}
long long minn(long long A,long long B){
    if(A<B)return A;
    else return B;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    long long py=0;
    for(int i=1,j=n;i<j;i++,j--){
            while(a[i]<=0){
                i++;
            }
            while(a[j]<=0){
                j++;
            }
      if(c[i]!=c[j]){
          ans+=minn(a[i],a[j]);
      }
      py=a[i]-a[j];
      if(a[j]<a[i]){
          int t=py;
        while(t-c[j-1]>=0){
            if(c[i]!=c[j-1])ans+=abss(c[j-1]);
            t-=c[j-1];
            j--;
        }
      }
      if(a[j]>a[i]){
          int t=py;
        while(t-c[i+1]>=0){
            if(c[i]!=c[i+1])ans+=abss(c[i+1]);
            t-=c[i+1];
            i++;
        }
      }
      if(a[i]<a[j])a[i+1]+=py;
      if(a[i]>a[j])a[j+1]-=py;
    }
    cout<<ans;
    return 0;
}
