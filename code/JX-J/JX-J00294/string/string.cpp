#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],sum=0;
char c[200005];
int huq(long long x){
    long long j=1,sum=0;
    while(sum<x){
        sum+=a[j];
        j++;
    }
    return j-1;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    if(n==1){
        cout<<0;
        return 0;
    }
    long long an1=0;
    for(int i=1;i<=sum/2;i++){
        if(c[huq(i)]!=c[huq(sum+1-i)]){
            an1++;
        }
    }
    cout<<an1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
