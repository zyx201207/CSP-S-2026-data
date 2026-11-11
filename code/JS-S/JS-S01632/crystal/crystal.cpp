// Oct31==Dec25? False
// luogu 1124559
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define sp ' '
#define int long long
/*
deep-diving...
thought:
-------------------------------------
do                         // time
sort a                     // n log n
calculate the qian zhui he // n
er fen and try             // n log n
------------sum------------// n log n
-------------------------------------
time to do it
*/
int n,m;
int a[500005],sum[500005];
bool chk(int x){
    for(int i=x;i<=n;i++){
        if(x*a[i]-(sum[i]-sum[i-x])<=m)return 1;
    }
    return 0;
}
signed main(){
    #ifndef LOCAL
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    int l=1,r=n,mid,ans=0;
    while(l<=r){
        mid=(l+r)/2;
        if(chk(mid)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}
/*
finish coding at 15:00
AC example*4 at 15:01 with 0 mistakes
AC example[big][self-made] at 15:31 with 0 mistakes
*/

/*
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define sp ' '
signed main(signed argc,char**argv){
    bool compile=1,run=1,runfiles=0;
    int filcnt=0;
    if(argc<1){
        cout<<"Please enter the cpp file name!";
        return 1;
    }
    string file=argv[1],t;
    if(file.find(".cpp")!=-1)file.erase((int)file.find(".cpp"),4);
    for(int i=2;i<argc;i++){
        t=argv[i];
        if(t=="-nc")compile=0;
        if(t=="-nr")run=0;
        if(t=="-rf"){
            i++;
            t=argv[i];
            bool f=1;
            for(int i=0;i<t.size();i++){
                if(!isdigit(i)){
                    f=0;
                    break;
                }
            }
            // if(f){
                run=0,runfiles=1;
                filcnt=stoi(t);
            // }
            // else{
            //     cout<<"[-rf *the file number*]";
            // }
        }
    }
    if(compile){
        string cmd;
        if(runfiles)cmd="g++ "+file+".cpp -o "+file+" -O2 -DLOCAL -std=c++14 -static -Wall";
        else cmd="g++ "+file+".cpp -o "+file+" -O2 -std=c++14 -static -Wall";
        system(cmd.c_str());
    }
    if(run){
        string cmd="time ./"+file;
        system(cmd.c_str());

    }
    if(runfiles){
        for(int i=1;i<=filcnt;i++){
            string cmd="time ./"+file+" < "+file+to_string(i)+".in > "+file+to_string(i)+"ot.out";
            system(cmd.c_str());
        }
    }
    return 0;
}
*/