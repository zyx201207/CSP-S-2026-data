#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
char c[200005];
int searchh(int k){
    int i1=0,sum=0;
    for(int i=n;i>=1;i--){
        sum=a[i]+sum;
        i1++;
        if(k<sum){
            break;
        }
    }
    return i1-1;
}
int stepp(long long sum){
    int cnt=0;
    long long aa=(sum/2);
    int cnti=0;
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=a[i];j++){
            cnti++;
            if(cnti>aa){
                break;
            }
            if(c[i]!=c[n-searchh(i)]){
                cnt++;
            }
        }
    }
    return cnt;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    cout<<stepp(sum);
    return 0;
}
