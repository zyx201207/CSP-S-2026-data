#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long long n;
	long long m;
	cin>>n>>m;
	long long s[n+5];
	for(long long i = 0;i<n;i++){
		cin>>s[i];
	}
	sort(s,s+n);
	long long bac[n+5];
	long long prep = 0;
	for(long long i = n-1;i>=0;i--){
		bac[i] = s[i]+prep;
		prep = bac[i];
	}
	long long cnt[n+5];
	prep = s[1];
	cnt[0] = 1;
	cnt[1] = 1;
	if(s[1]-s[0]<=m){
		cnt[1]+=1;
	}
	long long l,r,md;
	long long v,pp;
	for(long long i = 2;i<n;i++){
		cnt[i]=1;
		if(s[i] == prep){
			cnt[i]+=cnt[i-1];
			continue;
		}
		l = 0;
		r = i;
		while(1){
			md = (l+r)/2;
			v = (i-md)*s[i]-(bac[md]-bac[i]);
			if(r-l == 1){
				if((i-l)*s[i]-(bac[l]-bac[i])<=m){
					pp = i-l;
					break;
				}
				else{
					pp = i-r;
					break;
				}
			}
			if(v>m){
				l = md;
			}
			if(v<=m){
				r = md;
			}
			
		}
		cnt[i]+=pp;
		prep = s[i];
	}
	long long maxx = 0;
	for(long long i = 0;i<n;i++){
		maxx = max(maxx,cnt[i]);
	}
	cout<<maxx;
	return 0;
} 
