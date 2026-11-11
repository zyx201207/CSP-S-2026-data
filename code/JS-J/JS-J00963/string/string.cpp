#include<bits/stdc++.h>
using namespace std;
struct li{
    int l;
    char c;
}a[200005];
long long cnti;
long long cntj;
long long fn=0;
long long ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].l>>a[i].c;
    }
    cnti=a[1].l;
    cntj=a[n].l;
    for(int i=1,j=n;i<j;){
        if(cnti<cntj){
            if(a[i].c!=a[j].c){
                ans+=cnti-fn;
            }
            fn=cnti;
            i++;
            cnti+=a[i].l;
        }
        else if(cnti==cntj){
            if(a[i].c!=a[j].c){
                ans+=cnti-fn;
            }
            fn=cnti;
            i++,j--;
            cnti+=a[i].l;
            cntj+=a[j].l;
        }
        else if(cnti>cntj){
            if(a[i].c!=a[j].c){
                ans+=cntj-fn;
            }
            fn=cntj;
            j--;
            cntj+=a[j].l;
        }
    }
    cout<<ans;
    return 0;
}
