#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
long long a[1005];
char c[1005];
string st;
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i]>>c[i];
}
for(int i=1;i<=a[i];i++){
    st[i]=c[i];

}
int len=st.size();
int cnt=0;
for(int i=1;;i++){
    if(st[i]!=st[len-1]){
        cnt++;
    }
    if(st[i]>=st[len-1]){
        break;
    }
}
cout<<cnt;
return 0;
}
