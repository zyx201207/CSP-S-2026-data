#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long ans;
struct stb{
    long long a;
    char c;
}bf[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>bf[i].a>>bf[i].c;
    int posk=1,posw=n,k=0,w=0;
    while(posk<posw){
        if(bf[posk].c!=bf[posw].c){
            if(bf[posk].a>bf[posw].a){
                ans+=bf[posw].a;
                bf[posk].a-=bf[posw].a;
                posw--;
            }
            else if(bf[posk].a<bf[posw].a){
                ans+=bf[posk].a;
                bf[posw].a-=bf[posk].a;
                posk++;
            }
            else {
                ans+=bf[posk].a;
                posk++;
                posw--;
            }
        }
        else{
            if(bf[posk].a>bf[posw].a){
                bf[posk].a-=bf[posw].a;
                posw--;
            }
            else if(bf[posk].a<bf[posw].a){
                bf[posw].a-=bf[posk].a;
                posk++;
            }
            else {
                posk++;
                posw--;
            }
        }
    }
    cout<<ans;
    return 0;
}
