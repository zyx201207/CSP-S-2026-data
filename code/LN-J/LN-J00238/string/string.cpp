#include<bits/stdc++.h>
using namespace std;
int x,n=1;
long long ans;
struct STU {
    long long a;
    char c;
}a[200010];
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>x;
    for(int i=1;i<=x;i++) {
        long long t;
        char p;
        cin>>t>>p;
        if(i==1||a[n].c!=p) {
            a[n].a=t;
            a[n].c=p;
            n++;
        }
        else {
            a[n].a=a[n].a+t;
        }
    }
    n--;
    if(n==1) {
        cout<<0;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    int i=1,j=n;
    while(i<=j) {
        if(a[i].a>a[j].a) {
            a[i].a=a[i].a-a[j].a;
            if(a[j].c!=a[i].c) {
                ans=ans+a[j].a;
            }
            j--;
        }
        else if(a[i].a<a[j].a) {
            a[j].a=a[j].a-a[i].a;
            if(a[j].c!=a[i].c) {
                ans=ans+a[i].a;
            }
            i++;
        }
        else {
            if(a[j].c!=a[i].c) {
                ans=ans+a[i].a;
            }
            i++,j--;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
