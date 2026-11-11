#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin)
    freopen("string.out","w",stdout)
    int n,temp,num=0;
    char sb,t;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>temp;
        sb+=t*temp;
    }for(int i=0;i<n/2;i++){
        if(sb[i]==sb[1-i])else{num++;}
    }cout<<num;
    return 0;
}
