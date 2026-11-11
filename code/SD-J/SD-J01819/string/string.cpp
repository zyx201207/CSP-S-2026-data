#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using ll=long long;
struct node{
	ll cnt;
	char c;
} a[N];
ll b[150],x,n,maxx;
ll sum,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i].cnt>>a[i].c;
		b[a[i].c]+=a[i].cnt;
		sum+=a[i].cnt;
		maxx=max(maxx,a[i].cnt);
	}
	for(int i='a'; i<='z'; i++){
		if(b[i])x++;
	}
	if(x==1){
		cout<<"0\n";
		return 0;
	}
	if(sum<=5e8){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=a[i].cnt; j++){
				s.push_back(a[i].c);
			}
		}
		int l,r;
		for(int l=0,r=sum-1; l<r; l++,r--){
			if(s[l]!=s[r])ans++;
		}
		cout<<ans<<'\n';
	}
	else{
		cout<<min(sum/2,sum-maxx)<<'\n';
	}
	return 0;
}
/*
5
1 a
1 b
1 c
1 d
1 a

3
2 a
2 b
1 c
*/
