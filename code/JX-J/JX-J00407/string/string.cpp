#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans,l;
int a[200010];
char c[200010];
string s;
void hw(){
    if(ans%2==1){
        int mid=(ans/2)+1;
        string s1,s2;
        int d=0;
        for(int i=0;i<mid-1;i++){
            s1[d]=s[i];
            d++;
        }
        int f=0;
        for(int i=ans-1;i>=mid;i--){
            s2[f]=s[i];
            f++;
        }

        for(int i=0;i<d;i++){
            if(s1[i]!=s2[i]){
                l++;
            }
        }
    }else{
        int mid=ans/2;
        string s1,s2;
        int d=0;
        for(int i=0;i<mid;i++){
            s1[d]=s[i];
            d++;
        }
        int f=0;
        for(int i=s.size()-1;i>=mid+1;i--){
            s2[f]+=s[i];
            f++;
        }
        for(int i=0;i<mid;i++){
            if(s1[i]!=s2[i]){
                l++;
            }
        }
    }
    return;
}
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int k=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        ans+=a[i];
        for(int j=1;j<=a[i];j++){
            s[k]=c[i];
            k++;
        }
    }
    hw();
    cout<<l;
    return 0;
}
