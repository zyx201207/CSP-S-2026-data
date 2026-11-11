#include <bits/stdc++.h>

using namespace std;

struct zd{
    int num;
    char a;
}sz[200005];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long ans=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>sz[i].num>>sz[i].a;
    }
    int l=1,r=n,b=sz[1].num;
    while(true){
        if(l>=r){
            break;
        }
        if(b>0){
            if(sz[l].a!=sz[r].a){
                ans+=min(abs(b),sz[r].num);
            }
            if(abs(b)>sz[r].num){
                b-=sz[r].num;
                r--;
            }else if(abs(b)<sz[r].num){
                b-=sz[r].num;
                l++;
            }else{
                l++;
                r--;
                b = sz[l].num;
            }
        }else{
            if(sz[l].a!=sz[r].a){
                ans+=min(abs(b),sz[l].num);
            }
            if(abs(b)>sz[l].num){
                b+=sz[l].num;
                l++;
            }else if(abs(b)<sz[l].num){
                b+=sz[l].num;
                r--;
            }else{
                l++;
                r--;
                b = sz[l].num;
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
