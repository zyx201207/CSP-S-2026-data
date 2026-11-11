#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
int b[200005];
void q(int l,int cnt){
    for(int i=l;i<n;i++)
}
int main(){
    int sum=1;
    for(int i=1;i<=m;i++){
        sum*=n-i+1;
    }
    cout<<sum;
    return 0;
}
