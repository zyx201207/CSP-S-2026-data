#include<bits/stdc++.h>
using namespace std;
int n,sl=1,tn,times;
const int N1=2e5,N2=1e1;
char s[N1],ts;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>tn>>ts;
        for(int j=1;j<=tn;j++){
            s[sl]=ts;
            sl++;
        }
    }
    for(int l=1,r=sl-1;l<=r;l++,r--){
        if(s[l]!=s[r])times++;
    }
    cout<<times;
    //for(int i=1;i<=sl;i++)cout<<s[i];
    //ji de shan diao zhu shi o
    return 0;
}
