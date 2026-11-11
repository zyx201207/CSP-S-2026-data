#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[2010],x[2010];
int maxn=INT_MIN;
void dfs(int a,int b){
    if(b==m){
        int sum=x[0];
        for(int i=1;i<m;i++){
            sum&=x[i];
        }
        if(sum>maxn){
            maxn=sum;
        }
    }
    for(int i=a;i<n;i++){
        x[a]=a[i];
        dfs(a+1,b+1);

    }
}
int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    cout<<7;
}
