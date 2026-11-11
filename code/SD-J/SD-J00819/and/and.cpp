#include<bits/stdc++.h>
using namespace std;
long long n,m,a,ans=1,k=1;
struct an{
	string ss;
	int num;
}s[200010];
bool cmp(an x,an y){
	return x.num>y.num;
}
void changed(int a,int x){
	s[x].num=a;
	string t;
	while(a>0){
		t+=a%2+'0';
		a>>=1;
	}
	for(int i=t.size()-1;i>=0;i--) s[x].ss+=t[i];
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		changed(a,i);
	}
	sort(s+1,s+n+1,cmp);
	if(m==1){
		cout<<s[1].num;
		return 0;
	}
	return 0;
}
