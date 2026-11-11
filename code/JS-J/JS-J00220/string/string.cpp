#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct A{
    long long a;
    char c;
}st[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    string s;
    if(n==1)cout<<1;
    else{
        long long len=0;
        long long sum=0;
        for(int i=1;i<=n;i++){
            cin>>st[i].a;
            len+=st[i].a;
            cin>>st[i].c;
            s+=st[i].c;
        }
        long long L=1;
        long long R=n;
        while(L<=R){
            if(st[L].c!=st[R].c){
                sum+=min(st[L].a,st[R].a);
            }
            if(st[R].a>=st[L].a){
                st[R].a-=st[L].a;
                if(st[R].a==0){
                    R--;
                }
                L++;
            }
            else{
                st[L].a-=st[R].a;
                if(st[L].a==0){
                    L++;
                }
                R--;
            }
        }
        cout<<sum;
    }
    return 0;
}
