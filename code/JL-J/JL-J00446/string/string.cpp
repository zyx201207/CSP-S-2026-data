#include<bits/stdc++.h>

using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);


string s;
int n;
int b;
char a;
cin>>n;
cin>>a;
//for(int i=1;i<=n;i++){
    //s=s+a;
//}
for(int j=1;j<=s.size();j++){
    b=b+a[j];
}
for(int c=1;c<=b.size();c++){
    s=b/10%10;
}
return 0;
}

