#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
struct block{
    int num;
    char c;
}b[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b[i].num>>b[i].c;
    }
    ll ans=0;
    int lpos=1,rpos=n;
    while(lpos<=rpos){
        int diff=min(b[lpos].num,b[rpos].num);
        //cout<<lpos<<' '<<lnum<<' '<<rpos<<' '<<rnum<<endl;
        if(b[lpos].c!=b[rpos].c)ans+=diff;
        b[lpos].num-=diff;
        b[rpos].num-=diff;
        if(b[lpos].num<1){
            lpos++;
        }
        if(b[rpos].num<1){
            rpos--;
        }
    }
    cout<<ans;
	return 0;
}
