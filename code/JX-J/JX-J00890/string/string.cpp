#include<bits/stdc++.h>
using namespace std;
int n;
long long js;
const int N=200005;
struct zm{
    int a;
    char b;
}s[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].b;
    }
    int l=1,r=n;
    while(l<r){
        if(s[l].b==s[r].b){
            if(s[l].a<s[r].a){
                s[r].a-=s[l].a;
                l++;
                continue;
            }else if(s[l].a>s[r].a){
                s[l].a-=s[r].a;
                r--;
                continue;
            }else{
                l++;
                r--;
                continue;
            }
        }else{
            if(s[l].a<s[r].a){
                js=js+min(s[l].a,s[r].a);
                s[r].a-=s[l].a;
                l++;
                continue;
            }else if(s[l].a>s[r].a){
                js=js+min(s[l].a,s[r].a);
                s[l].a-=s[r].a;
                r--;
                continue;
            }else{
                js=js+s[l].a;
                l++;
                r--;
                continue;
            }
        }
    }
    cout<<js;
    return 0;
}
