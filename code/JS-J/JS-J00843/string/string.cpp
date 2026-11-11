#include<bits/stdc++.h>
using namespace std;
    struct ppm{
        long long a;
        string c;
    }cnt[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
        long long n,ans=0;
        cin>>n;
        for (long long i=0;i<n;i++){
            cin>>cnt[i].a>>cnt[i].c;
        }
        int e;
        for (long long i=0;i<n;i++){
                e=n-i-1;
            while (cnt[i].a!=0){
                if (e<0){break;}
                if (cnt[i].c!=cnt[e].c){
                        //cout<<i<<' '<<e;
                    if (cnt[i].a>=cnt[e].a){
                            ans+=cnt[e].a;
                        cnt[i].a-=cnt[e].a;
                        cnt[e].a=0;
                        e--;
                    }
                    else {
                        ans+=cnt[i].a;
                        cnt[e].a-=cnt[i].a;
                        cnt[i].a=0;
                    }
                }
                else {
                     if (cnt[i].a>=cnt[e].a){
                        cnt[i].a-=cnt[e].a;
                        cnt[e].a=0;
                        e--;
                    }
                    else {
                        cnt[e].a-=cnt[i].a;
                        cnt[i].a=0;
                    }
                }
            }
        }
        cout<<ans;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
