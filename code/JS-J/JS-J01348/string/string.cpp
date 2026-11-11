#include<bits/stdc++.h>
using namespace std;
int n,l,r,a[200010],cnt=0;
bool f=true;
string st;
char c[200010],q;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    q=c[1];
    for(int i=1;i<=n;i++){
        if(q!=c[i]){
            f=!f;
            break;
        }
    }
    if(f){
        cout<<"0";
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            st=st+c[i];
        }
    }
    l=1;
    r=st.size();
    while(l<=r){
        if(st[l]!=st[r]){
            cnt++;
        }
        l++;
        r--;
    }
    cout<<cnt;
    return 0;
}
