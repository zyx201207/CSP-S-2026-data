#include<bits/stdc++.h>
using namespace std;
long long n,a1[200005],ans=0;
char b1[200005];
vector<long long>a2;
vector<char>b2;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(long long i=0;i<n;i++){
        cin >> a1[i] >> b1[i];
        a2.push_back(a1[i]);
        b2.push_back(b1[i]);
    }
    reverse(a2.begin(),a2.end());
    reverse(b2.begin(),b2.end());
    long long l1=0,l2=0;
    while(l1!=n || l1!=l2){
        long long x1=a1[l1],x2=a2[l2];
        char y1=b1[l1],y2=b2[l2];
        if(x1>x2){
            x1-=x2;
            a1[l1]-=x2;
            l2++;
            if(y1!=y2)ans+=x2;
        }else if(x1<x2){
            x2-=x1;
            a2[l2]-=x1;
            l1++;
            if(y1!=y2)ans+=x1;
        }else{
            if(y1!=y2)ans+=x1;
            l1++;
            l2++;
        }
    }
    cout << ans/2;
}
