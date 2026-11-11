[#include<bits/stdc++.h>
using namespace std;
const int N=2e5+4;
struct Node{
    int c_len;
    char c;
}a[N],b[N];
int n,len=1;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    char last;
    int lastlen,alllen=0;
    for(int i=1;i<=n;++i){
        char tot;
        int num;
        cin >> num >> tot;
        alllen+=num;
        if(tot==last){
            lastlen+=num;
        }else{
            b[len]=a[len]={lastlen,last};
            len++;
            lastlen=num;last=tot;
        }
    }
    if(len==2){cout << 0;return 0;}
    reverse(b+1,b+n+1);
    int now=0,ans=0;
    for(int i=1,j=1;i<=n&&now*2<=n&&j<=n;){
        tot=min(a[i],b[j]);
        if(a[i].c!=b[j].c)ans+=len;

    }
}
