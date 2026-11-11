#include <bits/stdc++.h>
using namespace std;
long long n;
long long sz[200001];
char d[200001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    long long nl=0;
    for(int i=1;i<=n;i++){
        cin >> sz[i] >> d[i];
        nl+=sz[i];
    }
    long long nk=n;
    long long ans=0;
    long long i=1;
    long long tail=n;
    while(nk>1){
        long long c_sum=sz[i];
        if(c_sum>=(nl/2)+1){
            ans+=(nl-c_sum);
            break;
        }
        while(c_sum>=sz[tail]){
            //cout << tail << endl;
            nk--;
            nl-=sz[tail]*2;
            if(d[tail]==d[i]){
                c_sum-=sz[tail];
                tail--;
                continue;
            }
            c_sum-=sz[tail];
            ans+=sz[tail];
            tail--;
        }
        if(c_sum!=0){
            if(d[tail]!=d[i]){
                sz[tail]-=c_sum;
                nl-=c_sum*2;
                ans+=c_sum;
                //cout << sz[tail] << endl;
            }
            else{
                sz[tail]-=c_sum;
                nl-=c_sum*2;
            }
            //cout << tail << endl;
        }
        i++;
        nk--;
        //cout << endl;
        //cout << nl << ' ' << c_sum << ' ' << sz[tail] << endl;
    }
    cout << ans;
    return 0;
}
