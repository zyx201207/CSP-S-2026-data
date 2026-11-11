#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
pair<long long,char> s[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	int n;long long sum=0;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> s[i].first >> s[i].second;
		s[i].first+=s[i-1].first;
	}

	long long l=1,r=s[n].first,ans=0;
	int lidx=1,ridx=n;
	while(l<r){
		long long step=min(s[lidx].first-l+1,r-s[ridx-1].first);
		l+=step,r-=step;
		if(s[lidx].second!=s[ridx].second) ans+=step;
		if(l==s[lidx].first+1) lidx++;
		else ridx--;

	}
	
	cout << ans;	
	
	return 0;
}
