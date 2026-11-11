#include<bits/stdc++.h>
using namespace std;
int main()
{
preopen("string.in,"r",stdin);
preopen("string.out,"w",stdout);
long long n;
long long q;
string s[1005];
string y[1005];
int d=0;
for(int i=2;i ≤ n;i++)
{
    int a;
    string c;
    cin>>a>>c;
q+=a;
while(a>0)(
s[d]=c;
a--;
d++;
)
}
d=0;
for(int i=q;i>=0;i--){
y[d]=s[i];
}
int cnt=0;
for(int j=0;j<=q;j++){
    if(s[j]==y[j]){con}{}
    elso{cnt+=1;}
}
cout<<cnt;
return 0;
}

