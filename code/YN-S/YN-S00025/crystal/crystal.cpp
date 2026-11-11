// author fkxr lg uid 995934
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define in cin
#define out cout
namespace MYcode{
    const int N=5e5+5;
    int sum[N],a[N];
    void work(){
        int n,m;in>>n>>m;
        for(int i=1;i<=n;i++)in>>a[i];
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)
            sum[i]=sum[i-1]+a[i];
        int ans=1;
        for(int l=0,r=1;r<=n;r++){
            for(;(r-l)*a[r]-(sum[r]-sum[l])>m;)++l;
            ans=max(ans,r-l);
        }out<<ans<<"\n";
    }
}signed main(){
    string pid="crystal";
    freopen((pid+".in").c_str(),"r",stdin);
    freopen((pid+".out").c_str(),"w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    MYcode::work();
    return 0;
}
/*tester.cpp:
// author fkxr lg uid 995934
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define out cout
namespace MYcode{
    const string pb="./crystal/crystal",mycode="crystal";
    const int maxt=4;
    // int system(string s){
    //     out<<s<<"\n";
    //     return 0;
    // }
    void work(){
        system("rm -f ./*.myans");
        assert(!system(("g++ "+mycode+".cpp -o ./a -std=c++14 -O2").c_str()));
        for(int i=1;i<=maxt;i++){
            string id=pb+to_string(i);
            string run="./a <"+id+".in >"+id+".myans";
            string op="ulimit -s 524288 && ulimit -v 524288 && ulimit -t 524288 && time -f 'time :%e s,memory: %M KB' "+run;
            system(op.c_str());
            string cmp="diff -Bb "+id+".ans "+id+".myans";
            if(system(cmp.c_str())){
                out<<"WA on test #"<<i<<"\n";
                return;
            }else{
                out<<"#"<<i<<" was correct!\n";
            }
        }out<<"干的漂亮!\n";
    }
}signed main(){
    MYcode::work();
    return 0;
}
*/