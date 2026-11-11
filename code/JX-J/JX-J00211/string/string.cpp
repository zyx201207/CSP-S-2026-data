#include<bits/stdc++.h>
using namespace std;
int n;
struct qu{
    long long a;
    char c;
}s[200005];
long long ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%lld %c",&s[i].a,&s[i].c);
    }
    int i=1,j=n;
    while(i<j){
        if(s[i].c!=s[j].c){
            if(s[i].a<s[j].a){
                ans+=s[i].a;
                s[j].a-=s[i].a;
                i++;
            }
            else if(s[i].a>s[j].a){
                ans+=s[j].a;
                s[i].a-=s[j].a;
                j--;
            }
            else{
                ans+=s[i].a;
                s[i].a=s[j].a=0;
                i++;
                j--;
            }
        }
        else{
            if(s[i].a<s[j].a){
                s[j].a-=s[i].a;
                i++;
            }
            else if(s[i].a>s[j].a){
                s[i].a-=s[j].a;
                j--;
            }
            else{
                s[i].a=s[j].a=0;
                i++;
                j--;
            }
        }
    }
    cout<<ans;
    return 0;
}
