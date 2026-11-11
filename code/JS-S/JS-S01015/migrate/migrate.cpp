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
int c,t;
int n,d;
int a[2000005];
int b[2000005],len;
int nxt[2000005],pre[2000005];
int l[2000005],r[2000005];
int L[2000005],R[2000005];
int L2[2000005],R2[2000005];
int calc(int l1,int r1,int l2,int r2){
    if(l1>r1||l2>r2)return 0;
    if(r1<l2||l1>r2)return 0;
    if(l1>l2)swap(l1,l2),swap(r1,r2);
    return min(r1,r2)-l2+1;
}
int solve(int n){
   // cout<<n<<"\n";
    for(int i=1;i<=n;i++){
        L[i]=1ll<<60,R[i]=0;
        L2[i]=1ll<<60,R2[i]=0;
    }
    for(int i=1,j=1;i<=n;i++){
        while(j<n&&b[j+1]-b[i]<=d)j++;
        nxt[i]=j;
        L[j]=min(L[j],i);
        R[j]=max(R[j],i);
    }
    for(int i=n,j=n;i>=1;i--){
        while(j>1&&b[i]-b[j-1]<=d)j--;
        pre[i]=j;
        L2[j]=min(L2[j],i);
        R2[j]=max(R2[j],i);
    }
    if(n<=2)return 0;
    l[1]=1;
    for(int i=2;i<=n;i++){
        l[i]=1;
       l[i]+=calc(pre[i]+1,i-1,L[i],R[i]);
        if(nxt[pre[i]]==i){
            l[i]+=l[pre[i]];
        }
    }
    r[n]=1;
    for(int i=n-1;i>=1;i--){
        r[i]=1;
        r[i]+=calc(i+1,nxt[i]-1,L2[i],R2[i]);
        if(pre[nxt[i]]==i)r[i]+=r[nxt[i]];
    }
    int res=0;
    for(int i=3;i<n;i++){
        int c0=0,c1=0;
        if(pre[nxt[i]]==i-1)c0+=r[nxt[i]];
        c0+=calc(i+1,nxt[i]-1,L2[i-1],R2[i-1]);
        if(nxt[pre[i-1]]==i)c1+=l[pre[i-1]];
        c1+=calc(pre[i-1]+1,i-2,L[i],R[i]);
        res+=c0*c1;
    }
    return res;
}
void solve(){
    n=read(),d=read();
    for(int i=1;i<=n;i++)a[i]=read();
    b[1]=a[1],len=1;
    int res=0;
    for(int i=2;i<=n;i++){
        if(a[i]-a[i-1]<=d){
            b[++len]=a[i];
        }
        else{
            res+=solve(len);
            b[len=1]=a[i];
        }
    }
    res+=solve(len);
    cout<<res<<"\n";
}
bool Med;
signed main(){
    //cerr<<(&Mbe-&Med)/1048576.00<<"MB\n";
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read(),t=read();//t=1;
    while(t--)solve();
    return 0;
}
/*
g++ -std=c++14 -O2 -Wall -Wextra -Wshadow migrate.cpp -o migrate && ./migrate

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
