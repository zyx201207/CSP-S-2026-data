#include<bits/stdc++.h>
using namespace std;
const int N=0x3f3f3f3f;
int a[N];
char c[N];
string s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    long long n;
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++)
            s+=c[i];
    }
    int l=s.size();

    if(l%2){
        for(int i=1;i<=l/2;i++)
            for(int j=l/2+2;j<=l;j++)
                if(c[i]!=c[j]) cnt++;
    }else{
        for(int i=1;i<=l/2;i++)
            for(int j=l/2+1;j<=l;j++)
                if(c[i]!=c[j]) cnt++;
    }
    cout<<cnt;

    return 0;
}
