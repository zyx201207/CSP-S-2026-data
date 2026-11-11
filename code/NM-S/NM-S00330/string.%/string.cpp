#include <bits/stdc++.h>
using namespace std;
long long n,a[200010],i,m,ans;
char b[200010];
int main(){
        freopen("string.in","r",stdin);
        freopen("string.out","w",stdout);
        cin>>n;
        m=n;
        for(int i=1;i<=n;i++){
                cin>>a[i]>>b[i];
        }
        while(i<m){
                if(a[i]<a[m]){
                        if(b[i]!=b[m]){
                                ans+=a[i];
                        }
                        a[m]-=a[i];
                        a[i]=0;
                        i++;
                }
                else if(a[i]==a[m]){
                        if(b[i]!=b[m]){
                                ans+=a[i];
                        }
                        a[m]=0;
                        a[i]=0;
                        i++;
                        m--;
                }
                else{
                        if(b[i]!=b[m]){
                                ans+=a[m];
                        }
                        a[i]-=a[m];
                        a[m]=0;
                        m--;
                }
        }
        cout<<ans;
        return 0;
}
