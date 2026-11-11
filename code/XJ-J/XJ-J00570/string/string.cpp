#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=2e5+10;
int n;
ll siz[MAXN],l,r,len,ans;
char ch[MAXN];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>siz[i]>>ch[i];
        len+=siz[i];
    }
    l=0,r=0;
    int i=1,j=n;
    while(l+r<len&&i<=n&&j>=1){
        while(l>r&&j>=1&&l+r<len){
            r+=siz[j];
            if(ch[j]!=ch[i-1]){
                if(r>l)ans+=l-r+siz[j];
                else ans+=siz[j];
            }
            j--;
        }
        while(l<r&&i<=n&&l+r<len){
            l+=siz[i];
            if(ch[j+1]!=ch[i]){
                if(l>r)ans+=r-l+siz[i];
                else ans+=siz[i];
            }
            i++;
        }
        if(l==r&&i<=n&&j>=1&&l+r<len){
            
            l+=siz[i],r+=siz[j];
            if(ch[i]!=ch[j])ans+=min(siz[i],siz[j]);
            i++,j--;
        }
    }
    cout<<ans;
    return 0;
}