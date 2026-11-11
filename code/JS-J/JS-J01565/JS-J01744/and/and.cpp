#include<bits/stdc++.h>
#define int long long
const int N=1e6+10;
using namespace std;
int n,m,a[N];
string s="";
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        if(temp!=1&&temp!=2&&temp!=4&&temp!=8&&temp!=16&&temp!=32&&temp!=64&&temp!=128&&temp!=256&&temp!=512&&temp!=1024&&temp!=2048&&temp!=4096&&temp!=8192&&temp!=16384&&temp!=32768&&temp!=65536&&temp!=131072&&temp!=262144&&temp!=524288&&temp!=1048576&&temp!=2097152&&temp!=4194304&&temp!=8388608&&temp!=16777216&&temp!=33554432&&temp!=67108864&&temp!=134217728&&temp!=268435456&&temp!=536870912&&temp!=1073741824&&temp!=2147483648&&temp!=4294967296&&temp!=8589934592&&temp!=17179869184&&temp!=34359738368&&temp!=68719476736&&temp!=137438953472&&temp!=274877906944&&temp!=549755813888&&temp!=1099511627776&&temp!=2199023255552&&temp!=4398046511104&&temp!=8796093022208&&temp!=17592186044416&&temp!=35184372088832&&temp!=70368744177664&&temp!=140737488355328&&temp!=281474976710656&&temp!=562949953421312&&temp!=1125899906842624&&temp!=2251799813685248&&temp!=4503599627370496&&temp!=9007199254740992&&temp!=18014398509481984&&temp!=36028797018963968&&temp!=72057594037927936&&temp!=144115188075855872&&temp!=288230376151711744&&temp!=576460752303423488&&temp!=1152921504606846976&&temp!=2305843009213693952&&temp!=4611686018427387904) a[i]=temp;
    }
    sort(a,a+n,greater<long long>());
    cout<<a[m-1];
    return 0;

}
