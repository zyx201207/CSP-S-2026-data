#include<bits/stdc++.h>
using namespace std;
int a[200010];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        int c=a[i]+1;
        while(c%2==0){
            c/=2;
        }if(c==1){
            cout<<a[i+m-1];
            return 0;
        }
    }
    return 0;
}
