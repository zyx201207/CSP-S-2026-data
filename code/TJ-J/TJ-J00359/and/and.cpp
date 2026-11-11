#include<bits/stdc++.h>
using namespace std;
int a[20001];
int maxn=0;
int n,m;
int jj(int i,int j,int nnn){
    if(j==m){
        return a[i];
    }
    i++;
    for(;i<n;i++){
        if(j==m-1){
            maxn=max(maxn,(nnn & a[i]));
        }else{
            jj(i,j+1,nnn & a[i]);
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        jj(i,1,a[i]);
    }

    cout<<maxn<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
