#include <bits/stdc++.h>
using namespace std;
int n,m,a[5005],b[15000005],tail=0,head=0,c[5005];
int main(){
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    while(m--){
        for(int i=1;i<=n;i++){
            bool flag=0;
            b[tail++]=a[i];
            //cout<<tail<<endl<<endl;
            for(int j=tail-1;j>=0;j--){
                    cout<<b[j]<<' ';
                if(b[tail]==b[j]){
                    tail=j;
                    break;
                }
            }
            cout<<endl;
        }
        for(int i=1;i<=tail;i++){
            c[a[i]]++;
            //cout<<a[i]<<' ';
        }
        //cout<<endl;
    }
    for(int i=1;i<=n;i++){
        if(c[i]!=0){
            //cout<<c[i]<<' ';
        }
    }
    return 0;
}
