#include<bits/stdc++.h>
using namespace std;
const int N=10005;
struct zfc{
    int shu;
    string zm;
}a[N];
string q[N],h[N];
int main(){
    freopen("string.in",stdin);
    freopen("string.out",stdout);
    long long n,sumz=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].shu;
        cin>>a[i].zm;
        sumz+=a[i].shu;
    }
    long long sums=sumz,wz=0;
    while(sums!=0){
        int i=0;
        for(wz;wz<=a[i].shu;wz++){
            q[wz]=a[i].zm;
        }
        sums-=a[i++].shu;
    }
    string b[N];
    for(int i=0;i<sumz/2;i++){
        b[i]=q[sumz-i];
    }
    long long ql=0;
    if(sumz%2!=0) b[sumz/2]=q[sumz/2];
    for(int i=0;i<sumz/2;i++){
            if(q[i]!=b[i]) ql++;
    }
    cout<<ql;
    return 0;
}
