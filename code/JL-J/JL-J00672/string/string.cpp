#include<bits/stdc++.h>
using namespace std;
int n,a[200001],cmp2,cmp1,sum1,sum2=0;
char b[200001];
int Lsum(){
    int sum;
    for(int i=0;i<=n/2;i++){
        sum+=a[i];
    }
    return sum;
}
int main(){
    freopen("string.in","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        sum2+=a[i];
    }
    cmp2=n/2;
    if(cmp2%2==0) cmp1=cmp2-1;
    else{
        cmp1--;
        cmp2++;
    }
    if(sum1%2!=0){
        a[cmp1+1]--;
        sum1--;
    }
    for(;cmp2<n;cmp2++){
        if(a[cmp1]>a[cmp2]){
            while(a[cmp2]=a[cmp1]||Lsum()==sum1/2){
                int p=1;
                a[cmp1]++;
                a[cmp1-p]--;
                if(a[cmp1-p]=0) p++;
            }
        }
        if(a[cmp1]<a[cmp2]){
            while(a[cmp2]=a[cmp1]||Lsum()==sum1/2){
                int p=1;
                a[cmp2]++;
                a[cmp2+p]--;
                if(a[cmp2+p]=0) p++;
            }
        }
        cmp1--;
    }
    for(int i=0;i<n;i++){
        if(a[i]==0){
            for(int j=i;j<n;j++){
                a[j+1]=a[j];
                b[j+1]=b[j];
            }
            n--;
        }
    }
    cmp2=n/2;
    if(cmp2%2==0) cmp1=cmp2-1;
    else{
        cmp1--;
        cmp2++;
    }
    sum2=0;
    for(;cmp2<n;cmp2++){
        if(b[cmp1]!=b[cmp2]) sum2+=a[cmp1];
        cmp1--;
    }
    freopen("string.out","w",stdout);
    cout<<sum2;
    return 0;
}
