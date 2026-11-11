#include<bits/stdc++.h>

using namespace std;
const int N=200005;
int n;
long long ans;
int l,r;
struct ss{
    int a;
    char c;
}S[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
       S[i].a=a;
       S[i].c=c;
    }
  
    l=1;
    r=n;
   while(l<r){
       if(S[l].c!=S[r].c){
           if(S[l].a>S[r].a){
                S[l].a-=S[r].a;
                ans+=S[r].a;
                r--;
            }
            else if(S[l].a==S[r].a){
                ans+=S[l].a;
                r--;
                l++;
            
            }
            else if(S[l].a<S[r].a){
                S[r].a-=S[l].a;
                ans+=S[l].a;
                l++;
            }
       }
       else if(S[l].c==S[r].c){
           if(S[l].a==S[r].a){
               l++;
               r--;
           }
           else{
               if(S[l].a>S[r].a){
                   S[l].a-=S[r].a;
                   r--;
               }
               else{
                   S[r].a-=S[l].a;
                   l++;
               }
           }
       }
       
   }
    
    cout<<ans;
    return 0;
}