#include<bits/stdc++.h>

using namespace std;

long long n,m,crystals[500010],ans=1,use,Ans=-1,pivot;

void solveAB(int n){
	int D=m/n;
    for(int i=1;D>i;i++){
        ans++;
        D-=i;
    }
    cout<<ans+1;
}

void solve_1_to_9(){


    for(int i=0;i<n;i++){
        use=m;
        ans=1;
        pivot=crystals[i];
        for(int j=i+1;j<n && use>0;j++){
            if(use>=abs(pivot-crystals[j])){
                use-=(abs(pivot-crystals[j]));
                ans++;
                continue;
            }
            else break;
        }
        Ans=max(Ans,ans);
    }

    cout<<Ans;

    return ;
}

bool flag=1;
long long New,Old;


int main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;

    if(n==1) return(cout<<1,0);

    for(long long i=0;i<n;i++){
        cin>>crystals[i];
    }

    sort(crystals,crystals+n,greater<long long> ());
    for(int i=0;i<n;i++){
		if(i>0){
            New=abs(crystals[i-1]-crystals[i]);
            if(i!=1 && New!=Old){
                flag=0;
                break;
            }
            else if(i==1)Old=New;
		}
	}

    if(flag) solveAB(Old);
    else solve_1_to_9();

    return 0;
}

/*
2222    000    2222   6666       CCC    SSS   PPP        SSS         RRR    PPP     +       +
2  2   0   0   2  2   6         C      S      P  P      S            R  R   P  P    +       +
  2    0   0     2    6666      C       SS    PPP  ----  SS          RR     PPP   +++++   +++++
 2     0   0    2     6  6      C         S   P            S         R R    P       +       +
2222    000    2222   6666       CCC   SSS    P         SSS          R  R   P       +       +
*/
