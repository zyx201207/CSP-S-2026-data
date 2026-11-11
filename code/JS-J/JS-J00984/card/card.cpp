#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int ans[300005];
struct stu{
    bool p;int pos;
} book[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int k=0;k<n;k++){
        for(int i=k;i<n;i++){
            if(book[a[i]].p==1){
                for(int j=book[a[i]].pos+1;j<i;j++) book[a[j]].p=0;
                book[a[i]].p=1;
            }
            else {
                book[a[i]].p=1;book[a[i]].pos=i;
            }
        }
        for(int i=1;i<=m;i++) {
            if(book[i].p==1) ans[i]++;
            book[i].p=0;
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
