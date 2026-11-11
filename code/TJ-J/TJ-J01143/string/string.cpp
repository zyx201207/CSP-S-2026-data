#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int N;
int aa[MAXN];
char cc[MAXN];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>N;
	
	for(int i=1;i<=N;i++){
		cin>>aa[i]>>cc[i];
	}
	int la=aa[1],ra=aa[N];
	for(int l=1,r=N;l<=N&&r>l;){
		if(la>ra){
			la-=ra;
			if(cc[l]!=cc[r]) ans+=ra;
			r--;
			ra=aa[r];
		}else if(la<ra){
			ra-=la;
			if(cc[l]!=cc[r]) ans+=la;
			l++;
			la=aa[l];
		}else{
			if(cc[l]!=cc[r]) ans+=la;
			l++,r--;
			la=aa[l];
			ra=aa[r];
		}
	}
	cout<<ans;
	
	
	return 0;
}
