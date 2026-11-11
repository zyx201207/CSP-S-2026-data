#include<bits/stdc++.h>
using namespace std;
string a(long long int n,char b){
string f;
for(long long int i=0;i<n;i++){
f+=b;
}
return f;
}
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
long long int n,sum=0;
cin>>n;
string z;
for(long long int i=0;i<n;i++){
long long int x;
char c;
cin>>x>>c;
z+=a(x,c);
}
long long int l=z.size();
long long int s=0;

s=l/2;

long long int zuo=0;
long long int you=0;
string zo;
string yo;
for(long long int i=0;i<l;i++){
zo+=z[i];
zuo++;
yo+=z[l-i-1];
you++;
if(zuo==s){
    break;
}

}
for(long long int i=0;i<s;i++){
    if(zo[i]!=yo[i]){
        sum++;
    }
}
cout<<sum;
fclose(stdin);
fclose(stdout);
}
