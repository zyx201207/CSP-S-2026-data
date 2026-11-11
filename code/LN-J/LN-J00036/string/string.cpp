#include<bits/stdc++.h>
using namespace std;
struct Node{
    int a;
    char c;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,s1=0,s2=0,m1,m2;
    long long s=0;
    cin>>n;
    Node n1[n],n2[n];
    for(int i=0;i<n;i++){
        cin>>n1[i].a>>n1[i].c;
        n2[n-i-1].a=n1[i].a;
        n2[n-i-1].c=n1[i].c;
    }
    m1=n1[s1].a;
    m2=n2[s2].a;
    while(s1+s2<=n-1){
        long long m;
        m=min(m1,m2);
        if(n1[s1].c!=n2[s2].c){
            s+=m;
        }
        m1-=m;
        m2-=m;
        if(m1==0){
            s1++;
            m1=n1[s1].a;
        }
        if(m2==0){
            s2++;
            m2=n2[s2].a;
        }
    }
    cout<<s;
    return 0;
}
