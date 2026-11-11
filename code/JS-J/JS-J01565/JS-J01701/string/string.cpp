#include<fstream>
#include<cmath>
using namespace std;

int main(){
    ifstream fin("string.in");
    ofstream fout("string.out");

    long long n;
    long long a[200010];
    char b[200010];

    fin >> n;
    for(int i = 1; i<= n;i++){
        fin >> a[i];
        fin >> b[i];
    }
    long long ans = 0,lq = 1,rq = n,ll = 0,rl = 0;
    char llz = b[1],rlz = b[n];
    while(lq <= rq){
        if(ll > rl){
            while(ll != 0){
                if(ll <= a[rq]){
                    if(llz != b[rq])ans+=ll;
                    a[rq]-=ll;
                    ll = 0;
                }else{
                    if(llz != b[rq])ans+=a[rq];
                    ll-=a[rq];
                    a[rq] = 0;
                    rq--;
                    if(lq == rq)break;
                }
            }
            
        }else if(ll < rl){
            while(rl != 0){
                if(rl <= a[lq]){
                    if(rlz != b[lq])ans+=rl;
                    a[lq]-=rl;
                    rl = 0;
                }else{
                    if(rlz != b[lq])ans+=a[lq];
                    rl-=a[lq];
                    a[lq] = 0;
                    lq++;
                    if(lq == rq)break;
                }
            }
        }
        if(lq == rq)break;
        llz = b[lq],rlz=b[rq];
        if(b[lq] != b[rq]){
            ans+=min(a[lq],a[rq]);
        }
        ll = max(0ll,a[lq]-a[rq]);
        rl = max(0ll,a[rq]-a[lq]);

        lq++;
        rq--;
    }

    fout << ans;

    fin.close();
    fout.close();
    return 0;
}