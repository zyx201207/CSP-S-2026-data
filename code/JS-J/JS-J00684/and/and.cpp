#include<bits/stdc++.h>
using namespace std;
bool book[255555];
int a[255555];int n,m;
int ans=0;
void dfs(int k,int num){
    if(k>m){

        if(num>ans){

            ans=num;return;
        }
    }
    for(int i=1;i<=n;i++){
        if(book[i]==0){
            book[i]=1;
            dfs(k+1,(num&a[i]));
            book[i]=0;
        }
    }
}
int main(){

     freopen("and.in","r",stdin);
     freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    dfs(1,(~0));
//cout<<(1&a[1])<<endl;


    cout<<ans;


    return 0;
}
// 4 2 3 15 12 12
//5 3 31 3 1 15 7


