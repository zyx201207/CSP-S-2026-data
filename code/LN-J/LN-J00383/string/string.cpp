#include<bits/stdc++.h>
using namespace std;
int n;
long long sum=1,cnt;
char b[1000000005],x[50000005],y[500000005];
struct node{
    long long len;
    char s;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i].len >> a[i].s;
        for(int j=1;j<=a[i].len;j++){
            b[sum]=a[i].s;
            sum++;
        }
    }
    for(int i=1;i<=sum/2;i++){
        x[i]=b[i];
    }
    for(int i=sum;i>=int(ceil(sum*1.0/2));i--){
        y[i]=b[i];
    }
    for(int i=1;i<=sum/2;i++){
        if(x[i]!=y[i]){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
