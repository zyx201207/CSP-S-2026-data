#include<bits/stdc++.h>
using namespace std;
int a[200000];
char b[200000];
 int find(int n){
    int i = 1;
    int y = 0;
    int sum = 0;
    while(n>sum){
        sum+=a[i];
        y++;
        i++;
    }
    return y;
 }
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    //
    int k;
    cin>>k;
    int x;
    int n = 0;
    for(int i = 1;i<=k;i++){
        cin>>x>>b[i];
        a[i]=a[i-1]+x;
        n+=x;
    }
    int sum=0;
    for(int i = 1;i<=n/2;i++){
        int j = n-i+1;
        if(b[find(j)]!=b[find(i)]){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
