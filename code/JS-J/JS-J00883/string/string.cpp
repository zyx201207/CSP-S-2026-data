#include<bits/stdc++.h>
using namespace std;
long long n,ans;
struct as{
    int a;char c;
}a[200200];
long long l,r;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
   cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].a>>a[i].c;
        //scanf("%d",&a[i].a);
        //  scanf("%ch",a[i].c);

    }l=1,r=n;
    int x=a[l].a,y=a[r].a;
   // cout<<x<<" "<<y;
    while (l<r){
        if(x>y&&a[l].c!=a[r].c){
            ans+=y;
            x-=y;
            r--;
            y=a[r].a;
        }else if(x<y&&a[l].c!=a[r].c){
            ans+=x;
            y-=x;
            l++;
            x=a[l].a;
        }else  if(x==y&&a[l].c==a[r].c){

            l++;r--;
            x=a[l].a;
            y=a[r].a;
            }
        else if(x==y&&a[l].c!=a[r].c){
            ans+=x;
            l++;r--;
            x=a[l].a;
            y=a[r].a;
            }
        else if(x>y&&a[l].c==a[r].c){
            x=x-y;
            r--;
            y=a[r].a;
        }else {
            y-=x;
            l++;x=a[l].a;
        }
    }
    cout<<ans;
    return 0;
}
