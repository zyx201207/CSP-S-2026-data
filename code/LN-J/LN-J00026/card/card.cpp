#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
struct node{
    int num=0,c,cnt=0;
}b[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(b[a[j]].num!=0){
                for(int k=b[a[j]].c;k<=j;k++){
                    b[a[k]].num=0;
                    b[a[k]].c=0;
                }
                b[a[j]].num=1;
            }else{
                b[a[j]].num=1;
            }
            b[a[j]].c=j;
        }
        for(int j=1;j<=n;j++){
            if(b[a[j]].num!=0){
                b[a[j]].cnt++;
                b[a[j]].num=0;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i].cnt<<' ';
    }
    return 0;
}

