#include <bits/stdc++.h>
using namespace std;

int n;
int a[200000];
char c[200000];

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w",stdout);
    long long ans = 0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }
    int l_left=0, r_left=0, li=-1, ri=-1;
    while (li<n-1 || ri<n-1){
        // cout<<"L_LEFT "<<l_left<<", R_LEFT "<<r_left<<", LI "<<li<<", RI "<<ri<<", C "<<c[li]<<", "<<c[n-1-ri]<<endl;
        if (l_left==0) {li++; l_left+=a[li];}
        if (r_left==0) {ri++; r_left+=a[n-1-ri];}
        int t = min(l_left, r_left);
        l_left-=t;r_left-=t;
        if(c[li]!=c[n-1-ri]) ans+=t;
        // cout<<"|L_LEFT "<<l_left<<", R_LEFT "<<r_left<<", LI "<<li<<", RI "<<ri<<", C "<<c[li]<<", "<<c[n-1-ri]<<endl;
    }
    /*
    int ag=0, al=0, bg=0, bl=0;
    for(long long i=0;i<=length/2;i++){
        char l = c[ag], r = c[n-1-bg];
        if(l!=r)ans++;
        al++;
        if (al>=a[ag]) {al=0, ag++;}
        bl++;
        if (bl>=a[n-1-bg]) {bl=0, bg++;}
    }
    */
    cout<<ans/2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

