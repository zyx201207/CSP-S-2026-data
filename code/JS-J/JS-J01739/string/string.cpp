#include<bits/stdc++.h>
using namespace std;
long long n,l=1,r,a,k;
char inp;
struct p{
    int l,r;
    char c;
}s[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int j=1;
    for(int i=1;i<=n;i++){
        cin>>k>>inp;
        if(inp==s[j].c){
            l+=k;
            s[j].r=l;
        }else{
            j++;
            l++;
            s[j].l=l;
            l+=k;
            s[j].r=l;
        }
    }
    k=s[j].r;
    r=j;
    for(l=1;l<=j;l++){
        while(k-s[r].l<s[l].r){
            if(l==r){
                break;
            }
            if(s[r].c==s[l].c){
                r--;
                continue;
            }
            if((k-s[r].l>=s[l].r&&k-s[r].r<=s[l].l)){
                a+=s[l].r-s[l].l;
                r--;
                continue;
            }
            if((k-s[r].l<=s[l].r&&k-s[r].r>=s[l].l)){
                a+=s[r].r-s[r].l;
                r--;
                continue;
            }
            if((k-s[r].l<=s[l].r&&k-s[r].r<=s[l].l)){
                a+=k-s[r].l-s[l].l;
                r--;
                continue;
            }
            if((k-s[r].l>=s[l].r&&k-s[r].r>=s[l].l)){
                a+=s[l].r-k-s[r].r;
                r--;
                continue;
            }
        }
        if(l==r){
            break;
        }
        if(s[r].c==s[l].c){
            continue;
        }
        if((k-s[r].l>=s[l].r&&k-s[r].r<=s[l].l)){
            a+=s[l].r-s[l].l;
            continue;
        }
        if((k-s[r].l<=s[l].r&&k-s[r].r>=s[l].l)){
            a+=s[r].r-s[r].l;
            continue;
        }
        if((k-s[r].l<=s[l].r&&k-s[r].r<=s[l].l)){
            a+=k-s[r].l-s[l].l;
            continue;
        }
        if((k-s[r].l>=s[l].r&&k-s[r].r>=s[l].l)){
            a+=s[l].r-k-s[r].r;
            continue;
        }
    }
    cout<<a;
    return 0;
}
