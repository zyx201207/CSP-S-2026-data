#include<bits/stdc++.h>
using namespace std;
long long n,ans,l;
unsigned long long q;
struct Node{
    long long m;
    char k;
};
int main(){
     ios::sync_with_stdio(false);
     cin.tie(NULL);
     freopen("string.in","r",stdin);
     freopen("string.out","w",stdout);
     cin>>n;
     const long long p=n+1;
     Node s[p];
     for(int i =0;i<n;i++){
        cin>>s[i].m>>s[i].k;
        q=q+s[i].m;
     }
     long long cnt=0,nnt=0;
     for(int i=0;i<=q/2;i++){
        if(s[cnt].k==s[n-nnt-1].k){
            s[cnt].m-=1;
            s[n-nnt-1].m-=1;
            if(s[cnt].m==0){
                cnt+=1;
            }
            if(s[n-nnt-1].m==0){
                nnt+=1;
            }
        }else{
            ans+=1;
            s[cnt].m-=1;
            s[n-nnt-1].m-=1;
            if(s[cnt].m==0){
                cnt+=1;
            }
            if(s[n-nnt-1].m==0){
                nnt+=1;
            }
        }
        if(cnt==n-nnt-1||cnt==n-nnt&&s[cnt].m==0){
            cout<<ans;
            return 0;
        }
     }
}
