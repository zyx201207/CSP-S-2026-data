#include<bits/stdc++.h>
using namespace std;
int a[200000],ans=0,n;
void fun(int m,int sum,int i){
    if(m==0){
        ans=max(sum,ans);
    }
    for(;i<n;i++){
        fun(m-1,sum&a[i],i+1);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,i,j;
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    fun(m,2147483647,0);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
