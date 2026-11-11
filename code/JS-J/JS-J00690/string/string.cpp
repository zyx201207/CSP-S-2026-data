#include<bits/stdc++.h>
using namespace std;
struct node{
    long long sl;
    char ch;
}a[200000];
int main(){
//freopen("string.in","r",stdin);
//freopen("string.out","w",stdout);
long long n;
cin>>n;
string s="";
long long cnt=0;
for(int i=0;i<n;i++){
        cin>>a[i].sl>>a[i].ch;
    cnt+=a[i].sl;
}
long long ans=0;
long long i=0,j=0;
while(ans<cnt/2){
if(n-j-i-1==0){
    cnt-=(a[i].sl+1)/2;
    break;
}
ans+=min(a[i].sl,a[n-j-1].sl);
    if(a[i].ch==a[n-1-j].ch){
        cnt-=min(a[i].sl,a[n-j-1].sl);
    }int db=a[i].sl,po=a[n-j-1].sl;
    a[i].sl-=min(db,po);
    a[n-j-1].sl-=min(db,po);
        if(a[i].sl<=0){
            i++;
        }if(a[n-j-1].sl<=0){
            j++;
        }

}cout<<cnt/2;
    return 0;
}
