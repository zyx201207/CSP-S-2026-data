#include<bits/stdc++.h>
using namespace std;
struct node{
    long long b;
    char c;
}a[300000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,cnt=0;
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>a[i].b>>a[i].c;
    }
    long long r=0,l=n-1;
    while(r<=l){
        if(a[r].c!=a[l].c){
            if(a[r].b>a[l].b){
                cnt=cnt+a[l].b;
                a[r].b-=a[l].b;
                l--;
            }else if(a[r].b<a[l].b){
                cnt=cnt+a[r].b;
                a[l].b-=a[r].b;
                r++;
            }else{
                cnt+=a[r].b;
                a[r].b=0;
                a[l].b=0;
                r++;
                l--;
            }
        }else{
            if(a[r].b>a[l].b){
                a[r].b-=a[l].b;
                l--;
            }else if(a[r].b<a[l].b){
                a[l].b-=a[r].b;
                r++;
            }else{
                a[r].b=0;
                a[l].b=0;
                r++;
                l--;
            }
        }
    }
    cout<<cnt;
    return 0;
}
