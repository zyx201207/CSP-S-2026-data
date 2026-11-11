#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200007;
struct node{
    int a;
    char c;
}s[N];
int n,l,ans;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].c;
        l+=s[i].a;
    }
    int p=-1,cnt=0;
    for(int i=1,sum=0;i<=n;i++){
        sum+=s[i].a;
        if(sum>=l/2){
            p=i;
            cnt=sum-l/2;
            break;
        }
    }
    int i=1,j=n;
    while(i<j&&i<=p&&p<=j){
        if(s[i].c!=s[j].c){
            if(s[i].a>s[j].a){
                ans+=s[j].a;
                s[i].a-=s[j].a;
                s[j].c=s[i].c;
                j--;
            }else{
                ans+=s[i].a;
                s[j].a-=s[i].a;
                s[i].c=s[j].c;
                i++;
            }
        }else{
            if(s[i].a>s[j].a){
                j--;
            }else{
                i++;
            }
        }
    }
    cout<<ans;
    return 0;
}
/*
Think:
ben ti wo ren wei ta suan ban lia tan xin
why?
because hui wen bu shi you zhong xin
aaabb
jiushi meiyou
aaabbb
suo yi wo men zhi yao kan l/2 bu fen jiu zu gou le(zhong ixn buyong guan)
liang bian de bu tong

5
1 a
1 a
1 d
1 a
1 a
thank you for help

we need new
I think it isn't the best
XX|XX XX|X|XX

XXXXX
XXX
|
XX
XXXX

*/
/*

    int p=-1,cnt=0;
    for(int i=1,sum=0;i<=n;i++){
        sum+=s[i].a;
        if(sum>=l/2){
            p=i;
            cnt=sum-l/2;
        }
    }
    if(cnt>s[p].a/2)ans+=cnt-s[p].a/2;
    for(int i=1,j=n;i<=p;i++){
        int sum=0;
        while(sum+s[j].a<=s[i].a&&j>p){
            if(a[j].c!=a[i].c){
                ans+=s[j].a;
                sum+=s[j].a;
                j--;
            }
        }
        sum+=a[j].a;
        if(sum>a[i].a)ans+=sum-a[i].a;
    }
    cout<<ans
*/
