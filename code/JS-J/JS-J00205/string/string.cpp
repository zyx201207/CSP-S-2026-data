#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200005],b,ans=0,nl=0,nr=0,le=0,ri=0;
char c[200005],l,r;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        b+=a[i];
    }

        for(int i=1;i<=b/2;i++){

            le=i;
            ri=b+1-i;
            nl=0;
            nr=b+1;
            ll j=1;
            while(nl<le){
                nl+=a[j];
                l=c[j];
                j++;
            }
            j=n;
            while(nr>ri){
                nr=nr-a[j];
                r=c[j];
                j--;
            }
            if(l!=r){
                ans++;
            }

        }


    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;

}

