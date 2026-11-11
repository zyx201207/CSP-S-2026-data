#include<bits/stdc++.h>
using namespace std;
struct QAQ{
    int aa;
    char c;
}a[200005];
long long int s=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i].aa>>a[i].c;
    }
    int l=1,r=n;
    while(l<n){
        int lsmin=min(a[l].aa,a[r].aa);
        if(a[l].c!=a[r].c){
            s+=lsmin;
        }
        a[l].aa-=lsmin;
        a[r].aa-=lsmin;
        if(a[l].aa<=0)l++;
        if(a[r].aa<=0)r--;
    }
    cout<<s<<'\n';
    return 0;
}
//luogu:ETO_baizhou
//Although I will AFO ,I will remember my OI life forever.ty
//Maybe I need a ygg?plz
