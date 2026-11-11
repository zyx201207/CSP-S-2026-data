#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
struct PII{
    char c;
    ll a,id;
}s[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
long long sum=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].c;
        s[i].id=i;
    }
    for(int i=1,j=n;i<=n,j>=1;){
        if(i>j)break;
        if(s[i].c!=s[j].c){
            if(s[i].a>s[j].a){
                sum+=s[j].a;
                s[i].a-=s[j].a;
                j--;
            }else if(s[i].a==s[j].a){
                sum+=s[i].a;
                i++;
                j--;
            }else {
                sum+=s[i].a;
                s[j].a-=s[i].a;
                i++;
            }
        }else{
            if(s[i].a>s[j].a){
                s[i].a-=s[j].a;
                j--;
            }else if(s[i].a==s[j].a){
                i++;
                j--;
            }else {
                s[j].a-=s[i].a;
                i++;
            }
        }
    }
    cout<<sum;
    return 0;
}
