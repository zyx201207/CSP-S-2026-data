#include<bits/stdc++.h>
using namespace std;
long long n,a[2000005],ans;
char c[2000005];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int j=n;
    for(int i=1;i<j;i++){
        if(a[i]==a[j]&&c[i]!=c[j])ans+=a[i];
        else if(a[i]>a[j]){
            a[i]-=a[j];
            if(c[i]!=c[j])ans+=a[j];
            i--;
        }
        else if(a[i]<a[j]){
            a[j]-=a[i];
            if(c[i]!=c[j])ans+=a[i];
            j++;
        }
        j--;
    }
    cout<<ans;
    return 0;
}

