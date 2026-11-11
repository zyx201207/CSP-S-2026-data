#include</stdc++.h>
using namespace std;
int n,sz[200005],z,ch[200005];
char zm[200005];
long long xgs;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    z=n;
    for(int i=1;i<=n;i++){
        cin>>sz[i]>>zm[i];
        ch[i]=sz[i];
    }
    for(int i=1;i<=n;i++){
        while(sz[i]>0){
            if(sz[i]>=ch[z]){
                if(zm[i]!=zm[z])xgs+=ch[z];
                sz[i]-=ch[z];
                z++;
            }
            else{
                if(zm[i]!=zm[z])xgs+=sz[z];
                ch[z]-=sz[i];
                break;
            }
        }
    }
    cout<<xgs;
    return 0;
}
