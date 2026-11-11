#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
    int n=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        n=n*10+ch-'0';
        ch=getchar();
    }
    return n*f;
}
bool Mbe;
int n,m;
int a[500005];
int s[500005];
bool check(int l,int r){
    return a[r]*(r-l+1)-(s[r]-s[l-1])<=m;
}
bool Med;
signed main(){
    //cerr<<(&Mbe-&Med)/1048576.00<<"MB\n";
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        int res=i;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid,i)){
                res=mid,r=mid-1;
            }
            else l=mid+1;
        }
        ans=max(ans,i-res+1);
    }
    cout<<ans<<"\n";
    return 0;
}
/*
g++ -std=c++14 -O2 -Wall -Wextra -Wshadow crystal.cpp -o crystal

ulimit -s 998244353

Hey, it's me, it's Verity
Ask me anything
(oh I've got a question)
I know about a million things
I'll do everything
(ok) Oh what is the capital of France
oh oui oui oui
It is Paris
Merci
Oh what does the cow say
Oh moo moo moo
I speak that too
all day
Do you live alone
Is anybody home
1 2 3 and so....
Where did everybody go???
Hey it's me it's Verity
Ask me anything
I know about a million things
I'll do everything
Oh why's the door locked up so tight?
Oh tee hee hee
No need to leave
Stay here
why do you know where I sleep???
Oh I just know
I always know
I'm close
Do you live alone
Is anybody home
1 2 3 and so....
Where did everybody go???
come
Come closer
Come be my friend
Dont be so scared (Love me!!!)
Hey it's me it's Verity
Ask me anything
I know about a million things
I'll do everything
*/
