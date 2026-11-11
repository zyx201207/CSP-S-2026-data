#include<bits/stdc++.h>
#define N 200005
using namespace std;
long long size=0,cnt=0;
int a[N];
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    int n,r,l;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        size+=a[i];
    }
    l=0;r=n-1;
    while(r>l){
        int k=min(a[l],a[r]);
        if(c[r]!=c[l]){cnt+=k;}
        if(a[r]==a[l]){l++;r--;}
        else{
            if(a[r]>a[l]){l++;a[r]-=k;}
            else{r--;a[l]-=k;}
        }
    }
    cout<<cnt;
    return 0;
}
