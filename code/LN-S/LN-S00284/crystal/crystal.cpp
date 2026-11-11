#ifndef CRYSTAL_CPP_INCLUDED
#define CRYSTAL_CPP_INCLUDED
#include<bits/stdc++.h>
using namespace std;
#define int long long
int N=1e12+5;
int rd(){
    int x=0,k=1;
    char ch=getchar();
    while (ch<'0'||ch>'9'){
        if (ch=='-') k=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9'){
        x=x+(ch-'0');
        ch=getchar();
    }
    return k*x;
}
void wr(int x){
    if (x<0){
        putchar('-');
        x=-x;
    }
    if (x>9) wr(x/10);
    putchar(x%10+'0');

}
long long n,m;
vector<long long> a;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=rd();
    m=rd();
    a.resize(n+1);
    for (int i=0;i<n;i++){
        a[i]=rd();
    }
    sort(a.begin(),a.end());
    int l=0;
    for (int i=n-1;i>=1;i--){
        int target=a[i];
        int cnt=0;
        int j=i-1;
        for (;j>=1&&cnt+target-a[j]<=m;){
            cnt+=target-a[j];
            j--;
        }
        l=max(l,i-j);
    }
    wr(l);
    return 0;
}



#endif // CRYSTAL_CPP_INCLUDED
