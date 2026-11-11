#include<bits/stdc++.h>
using namespace std;
struct zb{
 int a;
 char b;
};
zb q[200004]={};
long long ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>q[i].a>>q[i].b;
    }
    int l=1,r=n;
    while(1){
       if(q[l].b==q[r].b){
        if(q[l].a==q[r].a){
            l++;
            r--;
        }
        else if(q[l].a>q[r].a){
            q[l].a=q[l].a-q[r].a;
            r--;
        }
        else{
            q[r].a=q[r].a-q[l].a;
            l++;
        }
       }
       else{
         if(q[l].a==q[r].a){
            ans=ans+q[l].a;
            l++;
            r--;
        }
        else if(q[l].a>q[r].a){
            q[l].a=q[l].a-q[r].a;
            ans=ans+q[r].a;
            r--;
        }
        else{
          q[r].a=q[r].a-q[l].a;
          ans=ans+q[l].a;
          l++;
        }
       }
       if(l>=r)break;
    }
    cout<<ans;
    return 0;
}
