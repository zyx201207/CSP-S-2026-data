#include<bits/stdc++.h>
using namespace std;
int a[100005]={0};
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int y=0,l=0;
    if(n%2==1){
        y=a[n/2+1];
    }else{
        y=a[n/2];
    }
    for(int i=1;i<=n;i++){
        if(a[i]==y){
            l=i;
        }
    }
    cout<<l;
    fclose(stdin);
    fclose(stdout);
}
