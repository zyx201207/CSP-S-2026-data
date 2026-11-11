#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin)
    freopen("and.out","w",stdout)
    int n,sb;
    cin>>n>>sb;
    int a[n],temp,num=-1;
    for(int i=0;i<n;i++){
    cin>>temp;a[i]=temp;
    }for(int i=1;i<n;i++){
    if(a[i]|a[i-1]>num)num=a[i]|a[i-1];
    }cout<<num;
    return 0;
}
