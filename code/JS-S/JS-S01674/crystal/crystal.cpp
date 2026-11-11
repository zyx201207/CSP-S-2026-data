#include<cstdio>
#include<algorithm>
using namespace std;

const int NMAX=5e5+10;
long long a[NMAX];
unsigned long long ans=1;
long long n,m;
unsigned long long chafen[NMAX];

inline void f(int num){
    chafen[num]=chafen[num-1]+(a[num]-a[num-1])*(num-1);
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);

    sort(a+1,a+n+1);
    chafen[1]=0;
    for(int i=2;i<=n;i++){
        f(i);
    }

    int l=1,r=1;
    while(l<=n&&r<=n){
        if(chafen[r]-chafen[l]<=m) r++;
        else{r++;l++;}
    }

    ans=r-l;
    printf("%d",ans);
    return 0;
}
/*
Quadruplicity(LucaProject vs NeLime) and Lament Rain(D-D-Dice vs Ashrount) are great songs
Waring: Poor English

14:12 trying completed
first time for CSPJ/S2
waiting for password...

14:20 creating folders and things

hoping for dp
experience the DEINOS PHAINE
wow lots of chocolate

Explore Designant.

14:28 ok I get the password

14:30 now we consider erfen for crystal
wow a[i]can<0
it is wrong

15:29 first ver for crystal writing

16:34 think crystal again
chafen is great
we calculate chafen[i] as we value which I use from 1 to i
then from t to s is chafen[s]-chafen[j]
O(n) is enough.

17:04 why sample 4 WA???

18:19 I am dying
*/
