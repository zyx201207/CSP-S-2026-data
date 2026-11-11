#include <bits/stdc++.h>
using namespace std;
int n,a[200010],c[21],m;
char s[200010][11];
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%s",&a[i],s[i]+1);
    int i=1,j=n;
    while(i!=j){
        int l=a[i],r=a[j];
        if(l<r){
            for(;i<j;i++){
                if(r>a[i]){
                    r-=a[i];
                    if(s[j][1]!=s[i][1])
                        ans+=1LL*a[i];
                }
                else{
                    a[i]-=r;
                    if(s[j][1]!=s[i][1])
                        ans+=1LL*r;
                    break;
                }
            }
            if(i==j)
                i--;
            j--;
        }
        else{
            for(;j>i;j--){
                if(l>a[j]){
                    l-=a[j];
                    if(s[i][1]!=s[j][1])
                        ans+=1LL*a[j];
                }
                else{
                    a[j]-=l;
                    if(s[i][1]!=s[j][1])
                        ans+=1LL*l;
                    break;
                }
            }
            if(j==i)
                j++;
            i++;
        }
    }
    while(ans>0)
        c[++m]=ans%10,ans/=10;
    for(int i=m;i>=1;i--)
        printf("%d",c[i]);
    printf("\n");
    return 0;
}
