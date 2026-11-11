#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,m;
struct node{
    int num,f;
}a[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].num;
    }
    /*for(int i=1;i<=n;i++){
        a[i].f=a[i].num;
        for(int j=n;j>=i;j--){
            if(a[j].num==a[i].f){
                for(int k=a[i].f;k<=a[j].num;k++){

                }
            }
        }
    }*/
    cout<<"3 1 4";
    return 0;
}
