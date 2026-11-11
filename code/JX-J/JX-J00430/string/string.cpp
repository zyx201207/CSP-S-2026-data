#include"bits/stdc++.h"
using namespace std;

struct st{
    char s;long n;
}a[200005];
long sum=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;
    int l=1,r=0;
    for(int i = 1;i <= n;i++){
        cin>>a[i].n>>a[i].s;
        r++;
    }
    while(l <= r){
        if(a[l].s == a[r].s){
            if(a[l].n == a[r].n){
                r--;l++;
               // cout<<1<<endl;
            }
            else if(a[l].n > a[r].n){
                //ll.s=a[l].s;
                a[l].n=a[l].n - a[r].n;
                r--;
                //cout<<2<<endl;
            }
            else if (a[l].n < a[r].n){
                //rl.s=a[r].s;
                a[r].n=a[r].n - a[l].n;
                l++;
                //cout<<3<<endl;
            }
        }
        else {
            if(a[l].n == a[r].n){
                r--;l++;
                sum += a[r].n*2;
                //cout<<4<<endl;
            }
            else if(a[l].n > a[r].n){
                //ll.s=a[l].s;
                sum+=min(a[l].n,a[r].n);
                a[l].n=a[l].n - a[r].n;
                r--;
                //cout<<5<<endl;
            }
            else if (a[l].n < a[r].n){
                //rl.s=a[r].s;
                sum+=min(a[l].n,a[r].n);
                a[r].n=a[r].n - a[l].n;
                l++;
                //cout<<6<<endl;
            }
        }
    }
    cout<<sum;
}
