#include<bits/stdc++.h>
#define ll long long
#define N 500010
using namespace std;
struct q{
    char c;
    ll s;
    ll biao;
}a[N];
ll n,d,w,ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    //cout<<1<<endl;
    for(int i=1;i<=n;i++){
        cin>>a[i].s>>a[i].c;
        d+=a[i].s;
    }
    //cout<<1<<endl;
    if(d%2==1){
        w=1;
        d+=1;
        d/=2;
    }
    else{
        d/=2;
    }
    for(int i=1;i<=n;i++){
        if(d>a[i].s){
            d-=a[i].s;
        }
        else{

            for(int j=n;j>i;j--){
                a[j+1].biao=a[j].biao;
                a[j+1].c=a[j].c;
                a[j+1].s=a[j].s;
            }
            a[i+1].c=a[i].c;
            a[i+1].s=a[i].s-d;
            a[i].s=d;
            if(w==1){
                a[i].s--;
            }
            a[i].biao=1;
        break;
        }
    }
    int i=1,j=n+1;

    while(1){//cout<<1<<endl;
        //   cout<<i<<" "<<j<<endl;
        if(i==j){
            break;
        }
        if(a[i].s==0){
                ++i;
            continue;
        }
        if(a[j].s==0){
            --j;
            continue;
        }
   //     cout<<ans<<" "<<i<<" "<<j<<" "<<endl;
        if(a[i].c==a[j].c){
            if(a[i].s>a[j].s){
                a[i].s-=a[j].s;
                j--;
            }
            else if(a[i].s==a[j].s){
                    a[j].s=0;
                i++;
            }
            else{
                a[j].s-=a[i].s;
                i++;
            }
        }
        else{
        //    cout<<114514<<endl;
            if(a[i].s>a[j].s){
                a[i].s-=a[j].s;
                ans+=a[j].s;
                j--;
            }
            else if(a[i].s==a[j].s){
                a[j].s=0;
                ans+=a[i].s;i++;
            }
            else{
                a[j].s-=a[i].s;
                ans+=a[i].s;
                i++;
            }
        }/*for(int i=1;i<=n+1;i++){
        cout<<a[i].biao<<" "<<a[i].c<<" "<<a[i].s<<endl;
        }*/

    }
    cout<<ans<<endl;
	return 0;
}
