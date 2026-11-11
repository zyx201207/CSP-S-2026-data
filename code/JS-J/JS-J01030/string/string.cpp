#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct fu{
    int a;
    char t;
}s[200086];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].t;
    }
    for(int i=1,j=n;i<=j;i++,j--){
        if(s[i].a==s[j].a){
            if(s[i].t==s[j].t){
                continue;
            }
            else ans+=s[i].a;
        }
        else if(s[i].a>s[j].a){
            if(s[i].t==s[j].t){
                s[i].a-=s[j].a;
                i--;
            }
            else{
                s[i].a-=s[j].a;
                i--;
                ans+=s[j].a;
            }
        }
        else{
            if(s[i].t==s[j].t){
                s[j].a-=s[i].a;
                j++;
            }
            else{
                s[j].a-=s[i].a;
                j++;
                ans+=s[i].a;
            }
        }
    }
    cout<<ans;
    return 0;
}
