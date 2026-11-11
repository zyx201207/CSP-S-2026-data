#include<bits/stdc++.h>
using namespace std;
stack<int> v;
bool aa[2001000];
int a[2001000];
int b[2001000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
       cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(aa[a[j]]){
                while(v.top()!=aa[a[j]]){
                    aa[v.top()]=false;
                    v.pop();
                }
            }
            else{
                aa[a[j]]=true;
                v.push(a[j]);
            }
        }
        while(!v.empty()){
            aa[v.top()]=false;
            b[v.top()]++;
            v.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
