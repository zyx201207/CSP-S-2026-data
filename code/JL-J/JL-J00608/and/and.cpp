#include<algorithm>
#include<cstring>
#include<cmath>
#include<iostream>
#include<iomanip>
using namespace std;
int a[1100];
int b[1100];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n;
    cin>>m;
    int sum=0;
    for(int i=0;i<=n;i++){
    for(int j=i;j<=m;j++){
        a[i]*a[j]=b[sum];
        sum++;
    }
    }
    return 0;
}
