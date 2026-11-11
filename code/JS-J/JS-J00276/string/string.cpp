#include<bits/stdc++.h>
using namespace std;
const  int N=2e5+10;
typedef long long ll;
ll n;
ll ans,num1,num2,d1,d2;
char c1,c2;
struct node{
    ll num;
    char c;
}a[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].num>>a[i].c;
    }
    c1=a[1].c;
    c2=a[n].c;
    num1=a[1].num;
    num2=a[n].num;
    d1=1;
    d2=n;
    while(d1<d2){
        if(num1>num2){
            if(c1==c2){
                num1-=num2;
                d2--;
                num2=a[d2].num;
                c2=a[d2].c;
            }
            else{
                ans+=num2;
                num1-=num2;
                d2--;
                num2=a[d2].num;
                c2=a[d2].c;
            }
        }
        else if(num1<num2){
            if(c1==c2){
                num2-=num1;
                d1++;
                num1=a[d1].num;
                c1=a[d1].c;
            }
            else{
                ans+=num1;
                num2-=num1;
                d1++;
                num1=a[d1].num;
                c1=a[d1].c;
            }
        }
        else{
            if(c1==c2){
                d1++;
                d2--;
                c1=a[d1].c;
                num1=a[d1].num;
                c2=a[d2].c;
                num2=a[d2].num;
            }
            else{
                ans+=num1;
                d1++;
                d2--;
                c1=a[d1].c;
                num1=a[d1].num;
                c2=a[d2].c;
                num2=a[d2].num;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
