#include<bits/stdc++.h>
using namespace std;
int a[500010],n,m,k;
int h[300010];
int heap[500010],head,tail;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        head=0,tail=0;
        for(int j=i;j<=n;j++){
            bool flag=true;
            for(k=head;k<=tail;k++)
                if(heap[k]==a[j]){
                    flag=false;
                    break;
                }
            if(flag==false){
                tail=k;
                continue;
            }
            heap[++tail]=a[j];
        }
        for(int j=head;j<=tail;j++)h[heap[j]]++;
    }
    for(int i=1;i<=m;i++)cout<<h[i]<<" ";
    return 0;
}
//24 pts maybe
//ccf give me 300 pts pls
//qu wan le
//yu gu 247pts
//2= or 1=?
