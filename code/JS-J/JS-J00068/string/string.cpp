#include <bits/stdc++.h>
using namespace std;

#define int long long
int cnt;
int now;
int n;
int len;
struct node{
    int v;
    string s;
}a[200010];

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].v>>a[i].s;
        len+=1LL*a[i].v;
    }
    int i=1,j=n;
    while(i<=j&&now<=len/2){
        if(len/2-now>=min(a[i].v,a[j].v)){
            if(a[i].v>a[j].v){

                now+=a[j].v;
                a[i].v-=a[j].v;
                if(a[i].s!=a[j].s){
                    cnt+=1LL*a[j].v;
                }
                j--;
                //cout<<now<<endl;
                //cout<<cnt<<endl;
            }
            if(a[i].v<a[j].v){
                now+=a[i].v;
                a[j].v-=a[i].v;
                if(a[i].s!=a[j].s){
                    cnt+=1LL*a[i].v;
                }
                i++;
                //cout<<2<<endl;
                //cout<<now<<endl;
                //cout<<cnt<<endl;
            }
            if(a[i].v==a[j].v){
                now+=a[i].v;
                if(a[i].s!=a[j].s){
                    cnt+=1LL*a[i].v;
                }
                i++;
                j--;
                //cout<<3<<endl;
                //cout<<now<<endl;
                //cout<<cnt<<endl;
            }
        }else{
            break;
        }
    }
    cout<<cnt;

    return 0;

}
