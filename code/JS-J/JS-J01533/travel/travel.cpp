#include<bits/stdc++.h>
using namespace std;
#define int long long
#define db double
#define ldb long double
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int,int>
#define pdi pair<double,int>
#define pid pair<int,double>
#define fi first
#define se second
#define fp(x) fixed<<setprecision(x)
#define lb lower_bound
#define ub upper_bound
#define lowbit(x) (x)&(-x)
#define pb push_back
#define pf push_front
#define ep emplace
#define eb emplace_back
#define mpr make_pair
int T=1;
string s1,s2,s3,s4;
char c1,c2;
bool ok1=0,ok2=0,ok3=0,ok4=0;
void print(){
    cout<<ok1<<ok2<<ok3<<ok4;
}
int check(char c){
    if(c>='A'&&c<='C'){
        return 1;
    }
    if(c=='D'||c=='F'){
        return 2;
    }
}
void solve(){
    //O(1) red
    cin>>s1>>s2>>s3>>s4;
    //cerr<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<"\n";
    if(s1[0]!=s3[0]||s1[1]!=s3[1]){
        print();
        return;
    }else{
        ok1=1;
        if(s2[0]!=s4[0]||s2[1]!=s4[1]){
            print();
            return;
        }else{
            ok2=1;
            c1=s2[2],c2=s4[2];
            if(check(c1)!=check(c2)){
                print();
                return;
            }else{
                ok3=1;
                if(c1>c2){
                    swap(c1,c2);
                }
                if(c1=='D'&&c2=='F'||c1=='A'&&c2=='B'||c1=='B'&&c2=='C'){
                    ok4=1;
                }
                print();
                return;
            }
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    //cin>>T;
    while(T--){
        solve();
    }
}
