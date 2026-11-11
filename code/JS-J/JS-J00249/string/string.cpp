#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,num[N],sum,cnt;
char ch[N],a[N],b[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int k=1;
    for(int i=1;i<=n;i++){
        cin>>num[i]>>ch[i];
        sum+=num[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=num[i];j++){
            a[k]=ch[i];
            b[sum+1-k]=ch[i];
            k++;
        }
    }
    for(int i=1;i<=sum;i++){
        cout<<a[i]<<" "<<b[i]<<"\n";
        if(a[i]!=b[i]) cnt++;
    }
    cout<<cnt/2;
    return 0;
}


