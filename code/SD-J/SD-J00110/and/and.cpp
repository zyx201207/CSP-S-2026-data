#include<bits/stdc++.h>
#define int long long
using namespace std;
struct ab{
	int a;
	string s;
	int num;
};
int c;
ab b[200050];
int n,m;
void abc(int x,int y){
	b[y].a=x;
	string ans="";
	while(x>0){
		int o=(x%2);
		ans+=o+'0';
		x/=2;
	}
	for(int i=0,j=ans.size()-1;i<=j;i++,j--){
		swap(ans[i],ans[j]);
	}
	b[y].s=ans;
	b[y].num=b[y].s.size();
	for(int i=0;i<=b[y].s.size()-1;i++){
		if(b[y].s[i]=='0'){
			b[y].num=i;
			break;
		}
	}
}
bool cmp(ab x,ab y){
	if(x.s.size()==y.s.size()){
		return x.num>y.num;
	}else{
		return x.s.size()>y.s.size();
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c;
		abc(c,i);
	}
	sort(b+1,b+n+1,cmp);
	int maxi=0,st;
	for(int i=1;i<=n;i++){
		if(b[i].num>maxi){
			st=i;
			maxi=b[i].num;
		}
	}int ans=b[st].a;
	for(int i=st+1;i<=st+m-1;i++){
		ans=ans&b[i].a;
	}
	cout<<ans;
	return 0;
}

