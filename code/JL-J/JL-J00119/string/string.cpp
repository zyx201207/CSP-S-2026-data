#include<bits/stdc++.h>
using namespace std;
int n,a[200001];
char c[200001];
long long ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int L=1,R=n;
    while(L<R){
        char tl=c[L],tr=c[R],cl=a[L],cr=a[R];
        if(cl<cr){
            if(tl!=tr){
                ans+=cl;
            }
            L++,a[R]-=cl;
        }
        if(cl>cr){
            if(tl!=tr){
                ans+=cr;
            }
            R--,a[L]-=cr;
        }
        if(cl==cr){
            if(tl!=tr){
                ans+=cl;
            }
            L++,R--;
        }
    }
    cout<<ans;
}
