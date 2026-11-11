#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
long long tot;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int i=1,j=n,s1=a[1],s2=a[n];
    while(i!=j){
        if(c[i]!=c[j]){
            tot+=min(s1,s2);
        }
        if(s1>=s2){
            s1-=s2;
            j--;
            s2=a[j];
        }
        else{
            s2-=s1;
            i++;
            s1=a[i];
        }
    }
    cout<<tot;
    return 0;
}
