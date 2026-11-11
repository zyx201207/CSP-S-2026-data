#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200010],ans;
char c[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int j=n;
    for(int i=1;i<j;){
        if(c[j]!=c[i]){
            if(a[i]>a[j]){
                c[j]=c[i];
                ans+=a[j];
                a[i]-=a[j];
                a[j]=0;
                j--;
            }else{
                c[i]=c[j];
                ans+=a[i];
                a[j]-=a[i];
                a[i]=0;
                i++;
            }
        }else{
            if(a[i]>a[j]){
                a[i]-=a[j];
                a[j]=0;
                j--;
            }else{
                a[j]-=a[i];
                a[i]=0;
                i++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}