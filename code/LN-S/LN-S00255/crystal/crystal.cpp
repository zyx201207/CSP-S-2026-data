#include <bits/stdc++.h>
using namespace std;
const int N=5e5+1;
long long a[N];
long long tnt=0,ans=1;
long long n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
        cin>>a[i];
	}
    sort(a+1,a+n+1);
    long long tnt=0;
	for(long long i=1;i<=n;i++){
        bool ok=true;
        bool op=true;

        for(long long j=1;j<=n;j++){
			for(long long k=2;k<=n;k++){
				if(a[k]!=a[k-1]) op=false;
			}
			if(op){cout<<n; return 0;}
            if(m-((a[i+j]-a[j])*j)>=0){
                m-=((a[i+j]-a[j])*j);
                ans++;
            }else{
                ok=false;
                break;
            }

        }
        if(ok==false) break;
	}
	cout<<ans;
	return 0;
}
