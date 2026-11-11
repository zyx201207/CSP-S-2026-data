#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[500005],m,t[300005];
int mm[300005];
stack<int> s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }for(int i=1;i<=n;i++){
        memset(mm,0,sizeof(mm));
        for(int j=i;j<=n;j++){
            if(mm[a[j]]==0){
                s.push(a[j]);
                mm[a[j]]++;
            }else{
                while(mm[a[j]]!=0){
                    mm[s.top()]-=1;
                    s.pop();
                }s.push(a[j]);
                mm[a[j]]++;
            }
        }for(int j=1;j<=m;j++){
            t[j]+=mm[j];
        }
    }
    for(int j=1;j<=m;j++){
        cout<<t[j]<<' ';
    }
    return 0;
}
/*
         ___
        /|  \
        | | |





*/
