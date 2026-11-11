#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    struct tri{
        long long a;
        char s;
    };
    int n;
    long long k=0, s=0;
    cin >> n;
    tri m[n];
    for (int i=0;i<n;i++){
        cin >> m[i].a >> m[i].s;
        s+=m[i].a;
    }int ks, l=0, r=n-1;
    if (s%2==0)ks=s/2+1;
    else ks=s/2+2;
    while (s>0 && l<r){
        if (m[l].s!=m[r].s){
            if (m[l].a<m[r].a){
                k+=m[l].a;
                m[r].a-=m[l].a;
                s-=m[l].a*2;
                m[l].a=0;
            }
            else{
                k+=m[r].a;
                m[l].a-=m[r].a;
                s-=m[r].a*2;
                m[r].a=0;
            }
            if (m[r].a==0)r--;
            if (m[l].a==0)l++;
        }
        if (m[l].s==m[r].s){
            if (m[l].a<m[r].a){
                m[r].a-=m[l].a;
                s-=m[l].a*2;
                m[l].a=0;
            }
            else{
                m[l].a-=m[r].a;
                s-=m[r].a*2;
                m[r].a=0;
            }
            if (m[r].a==0)r--;
            if (m[l].a==0)l++;
        }
    }
    cout << k;
    return 0;
}
