#include<bits/stdc++.h>
using namespace std;
string m;
int n,a,as;
char w;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
   //int as=0;
    cin>>n;
    for(int i=0;i<=n;i++){
        cin>>a>>w;
        for(int j=1;j<=a;j++){
            m[j+1]==w;
        }
    }
    for(int i=1;i<=n;i++){
        if(m[i]!=m[n-1]){
            as++;
        }
    }
    cout<<n<<m;
    return 0;
}
