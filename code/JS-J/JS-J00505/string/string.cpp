#include<bits/stdc++.h>
using namespace std;
struct s{
    int f;
    char s;
}a[100000];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n,m;
    long long ans=0;
    char c;
    string s;
    cin>>n;
    int i=0,j=0,ij;
    for(;i<n;i++){
        cin>>a[i].f;
        cin>>a[i].s;
    }
    while(j<=i){
        int A=min(a[j].f,a[i].f);
        if(a[j].s!=a[i].s){
            ans+=A;
        }
        a[j].f-=A;
        a[i].f-=A;
        if(a[j].f<=0) j++;
        if(a[i].f<=0) i--;
    }
    cout<<ans;


    fclose(stdin);
    fclose(stdout);
    return 0;
}
