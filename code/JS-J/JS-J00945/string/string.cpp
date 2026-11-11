#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,al,ans;
int Cn;
char Cl;
struct str{
    int num;
    char ltr;
}a[200010];
int f[200010];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        scanf("%d %c",&Cn,&Cl);
        a[i].num = Cn;
        a[i].ltr = Cl;
        f[i] = al+1;
        al+=Cn;
    }
    f[n+1] = al+1;
//    cout<<endl;
//    for(int i = 1;i<=n;i++){
//        cout<<a[i].num<<" "<<a[i].ltr<<endl;
//    }
//    cout<<endl;
    int it = n;
    for(int i = 1;f[i]<=al/2;i++){
        int l = f[i],r = f[i+1]-1;
        l = al+1-l;r = al+1-r;
        swap(l,r);
        l = max(l,al/2);
        while(f[it]>r)it--;
        while(it!=0&&f[it+1]-1>=l){
            if(a[it].ltr!=a[i].ltr){
                ans+=min(f[it+1]-1,r)-max(f[it],l)+1;
            }
            it--;
        }
        it++;

//        cout<<ans<<" "<<it<<endl;
    }
    cout<<ans;
    return 0;
}
