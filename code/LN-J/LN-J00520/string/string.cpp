#include<bits/stdc++.h>
using namespace std;
struct node{
    long long a;
    char c;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    unsigned long long ans=0;
    cin>>n;
    if(n==1) cout<<0;
    else {
        node l[n];
        for(int i=0;i<n;i++){
            cin>>l[i].a>>l[i].c;
        }
        long long i=0,j=n-1;
        while(i<=j){
            if(l[i].c!=l[j].c){
                ans+=min(l[i].a,l[j].a);
                if(l[i].a<l[j].a){
                    if(l[j].c!=l[i+1].c){
                        ans+=l[j].a-l[i].a;
                    }
                    else if(l[j].c==l[i+1].c){
                        ans-=l[j].a-l[i].a;
                    }
                }
                else if(l[i].a>l[j].a){
                    if(l[i].c!=l[j-1].c){
                        ans+=l[i].a-l[j].a;
                    }
                    else if(l[i].c==l[j-1].c){
                        ans-=l[i].a-l[j].a;
                    }
                }
            }
            i++;j--;
        }
        cout<<ans;
    }
    return 0;
}
