#include<bits/stdc++.h>
using namespace std;
struct node{
    char id;
    long long v;
}a[205005];
int n,l,i1;
long long sum,cnt;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        long long x;
        char c;
        cin>>x>>c;
        a[i].v=x;
        a[i].id=c;
        sum+=x;
    }
    long long o=ceil(sum*1.0/2),b=0;
    for(int i=1;i<=n;i++){
       if(b<=o){
          b+=a[i].v;
       }else{
           a[i].v=a[i].v;
           l=i;
           break;
       }
   }
   i1=1;
//aabbc
   for(int i=n;i>=l;i){
        if(a[i].v<=0) i--;
        if(a[i1].v<=0)  i1++;
        if(a[i].id!=a[i1].id){
            //cout<<cnt<<endl;
            cnt+=min(a[i].v,a[i1].v);
            if(a[i1].v>=a[i].v){
                a[i1].v-=a[i].v;
                i--;
            }
            else {
                a[i].v-=a[i1].v;
                i1++;
                //cnt+=a[i1].v;
            }

        }else{
        if(a[i1].v>=a[i].v){
                a[i1].v-=a[i].v;
                i--;
            }
            else {
                a[i].v-=a[i1].v;
                i1++;
            }

        }
   }
   cout<<cnt;
    return 0;
}
