#include<bits/stdc++.h>
using namespace std;
long long n,m,energy[1000000],cnt[1000000];
long long num,mx=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%ld%ld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%ld",&energy[i]);
	}
	sort(energy+1,energy+1+n);
	for(int i=1;i<n;i++){
		cnt[i]=energy[i+1]-energy[i];
	}
	for(long long l=1;l<n;l++){
		num=0;
	    for(long long r=l+1;r<=n+1;r++){
	    	if(cnt[r-1]>m||num+(r-l)*cnt[r-1]>m||num+1>m){
	    		mx=max(r-l,mx);
	    		break;
			}
			num+=(r-l)*cnt[r-1];
		}
    }
    printf("%ld",mx);
	return 0;
}