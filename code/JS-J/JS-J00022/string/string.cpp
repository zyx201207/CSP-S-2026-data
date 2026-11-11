#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char c[200005];
long long sum;
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
        cin>>c[i];
    }
    int l=0,r=n-1;
    long long h1=0,h2=sum/2;
    while(h1<sum/2 && h2>0){
        if(l==r){
            break;
        }
        int b=min(a[l],a[r]);
        if(c[l]!=c[r]){
            ans+=b;
        }
        h1+=b;
        h2-=b;
        a[l]-=b;
        a[r]-=b;
        if(a[l]==0){
            l++;
        }
        if(a[r]==0){
            r--;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
