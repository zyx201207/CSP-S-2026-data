#include<bits/stdc++.h>
using namespace std;
int n,num,pos,cnt;
char c,ch[1000000005];
int huiwen(char str[1000000005]){
    int q=pos/2;
    if (pos%2==1){
        q++;
        int epsil=0;
        for (int i=1;i<=q-1;i++)
            if (ch[q-(++epsil)]!=ch[q+epsil])
                cnt++;
    }
    else{
        int epsil=0;
        for (int i=1;i<=q;i++)
            if (ch[q-(++epsil)+1]!=ch[q+epsil])
                cnt++;
    }
    return cnt;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>num>>c;
        for (int j=1;j<=num;j++)
            ch[++pos]=c;
    }
    cout<<huiwen(ch);
    return 0;
};
