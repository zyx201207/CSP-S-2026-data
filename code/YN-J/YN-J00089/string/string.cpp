#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
struct node{
    ll num;
    char ch;
}a[N];
ll n,ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].num>>a[i].ch;
//    cout<<"n:"<<n<<'\n';
//    for(int i=1;i<=n;i++)cout<<a[i].num<<' '<<a[i].ch<<'\n';
    ll l=1,r=n,num1=a[1].num,num2=a[n].num;
//    cout<<"num1:"<<num1<<" num2:"<<num2<<'\n';
    while(l<=r){
        if(a[l].ch==a[r].ch){
//          cout<<"YES\n";
            if(num1==num2){
                l++,r--;
                num1=a[l].num,num2=a[r].num;
            }
            else if(num1>num2){
                num1-=num2;
                r--;
                num2=a[r].num;
            }
            else{
                num2-=num1;
                l++;
                num1=a[l].num;
            }
            continue;
        }
        if(num1>num2){
            ans+=num2;
            num1-=num2;
            r--;
            num2=a[r].num;
        }
        else if(num1==num2){
            ans+=num1;
            l++,r--;
            num1=a[l].num,num2=a[r].num;
        }
        else{
            ans+=num1;
            num2-=num1;
            l++;
            num1=a[l].num;
        }
    }
    cout<<ans;
    return 0;
}
