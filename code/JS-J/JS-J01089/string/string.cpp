#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[200067];ll s[200067];
char c[200067];
string t="";

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;
    ll len=0;
    int aimin=1067676767;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        s[i]=s[i-1]+a[i];
        len+=a[i];
        aimin=min(aimin,a[i]);
    }
    if(aimin<=500){
        for(int i=1;i<=n;i++){
            for(int j=0;j<a[i];j++){
                t+=c[i];
            }
        }
        int ans=0;
        for(int i=0,j=t.size()-1;i<t.size()/2;i++,j--){
            if(t[i]!=t[j])ans++;
        }
        cout<<ans;
        return 0;
    }
    int oe=len%2;
    ll half=len/2;
  //  for(int i=0;i<=n;i++){
  //      cout<<s[i]<<endl;
 //   }
    int rv;
    for(int i=0;i<=n;i++){
        if(s[i]<=half&&half<s[i+1]){
            rv=i+(half-s[i]>s[i+1]-half-oe);
            int cut=min(half-s[i],s[i+1]-half-oe);
            a[i+1]-=cut*2+oe;
            break;
        }
    }
  //  cout<<rv<<endl;
    half=0;
    for(int i=1;i<=rv;i++)half+=a[i];
   // for(int i=1;i<=n;i++){
  //      cout<<a[i]<<' '<<c[i]<<endl;
  //  }
    ll rem=0,ans=0;
    for(int i=0,j=n+1;i<=rv&&j-i>1;){
        if(rem==0){
            i++;j--;
            int step=min(a[i],a[j]);
            rem=a[i]-a[j];
            if(c[i]!=c[j])ans+=step;
        }
        if(rem>0){
            int step=rem;
            j--;
            rem-=a[j];
            if(c[i]!=c[j])ans+=step;
        }
        if(rem<0){
            int step=-rem;
            i++;
            rem+=a[i];
            if(c[i]!=c[j])ans+=step;
        }
//        cout<<i<<' '<<j<<endl;
    }
    cout<<ans;
    return 0;
}
