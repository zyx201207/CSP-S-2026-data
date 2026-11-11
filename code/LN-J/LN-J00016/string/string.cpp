#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=200010;
int a[N],b[N];
char c[N];
void init(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
}
signed main(){
    init();
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,sum=0;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i] >> c[i];
        sum+=a[i];
        b[i]=a[i];
    }int mid=ceil(sum*1.0/2);
    int midi=1,ans=0;
    while(mid>0){
        if(b[midi]!=0){
            b[midi]-=mid;
            if(b[midi]<=0){
                mid=abs(b[midi]);
                b[midi]=0;
            }else{
                mid=0;
            }
        }midi++;
    }
    for(int i=1,j=n;i<j;){
        if(c[j]!=c[i]){
            if(a[i]>b[j]){
                ans+=b[j];
                a[i]-=b[j];
                j--;
            }else if(a[i]==b[j]){
                ans+=b[j];
                i++;
                j--;
            }else{
                ans+=a[i];
                b[j]-=a[i];
                i++;
            }
        }else{
            if(a[i]>b[j]){
                a[i]-=b[j];
                j--;
            }else if(a[i]==b[j]){
                i++;
                j--;
            }else{
                b[j]-=a[i];
                i++;
            }
        }
    }cout << ans << '\n';
    return 0;
}
