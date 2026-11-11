#include <iostream>
using namespace std;
string s,a,b;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,x,num=0,sum=0;
    char y;
    cin>>n;
    if(n==1){cout<<"0"<<endl;return 0;}
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        num+=x;
        while(x--) s+=y;
    }
    if(num%2==0) {
        for(int i=0;i<num/2;i++) a+=s[i];
        for(int i=num-1;i>=num/2;i--) b+=s[i];
        for(int i=0;i<num/2;i++) if(a[i]!=b[i]) sum++;
        cout<<sum<<endl;
    } else {
        for(int i=0;i<(num-1)/2;i++) a+=s[i];
        for(int i=num-1;i>(num-1)/2;i--) b+=s[i];
        for(int i=0;i<(num-1)/2;i++) if(a[i]!=b[i]) sum++;
        cout<<sum<<endl;
    }
}
