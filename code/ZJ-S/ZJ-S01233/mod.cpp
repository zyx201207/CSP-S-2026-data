#include<bits/stdc++.h>
#define gc getchar
#define pb push_back
#define vci vector<int>
#define fr(i,l,r) for(int i=l;i<=r;i++)
#define gr(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
inline int read(){
    int x=0;char ch=gc();bool fg=0;
    while(!isdigit(ch)) fg^=ch=='-',ch=gc();
    while(isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=gc();
    return fg?~(x-1):x;
}
signed main(){

    return 0;
}