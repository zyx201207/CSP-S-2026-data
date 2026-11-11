#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=2e5+100;
int n,cnt;
char lst='?';
struct node{
	int x;
	char ch;
};
vector<node> k,t;
signed main(){
	FIO
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		int x;
		char ch;cin>>x>>ch;
		if(ch==lst||lst=='?') cnt+=x;
		else k.push_back({cnt,lst}),cnt=x;
		lst=ch;
	}
	if(cnt) k.push_back({cnt,lst});
	int sum=0;
	for(int i=0;i<k.size();i++)
		sum+=k[i].x;
	int l=0,mid;
	for(int i=0;i<k.size();i++){
		l+=k[i].x;
		if(l>=sum/2) {
			if(l==sum/2) t.push_back(k[i]);
			else {
				t.push_back({sum/2-(l-k[i].x),k[i].ch});
				t.push_back({l-sum/2-(sum%2),k[i].ch});
			}
			for(int j=i+1;j<k.size();j++)
				t.push_back(k[j]);
			break;
		}else t.push_back(k[i]);
	}
	l=0;
	int r=t.size()-1,cnt_l=t[0].x,cnt_r=t.back().x,ans=0;
	while(l<r){
		int s=min(cnt_l,cnt_r);
		ans+=min(cnt_l,cnt_r)*(t[l].ch!=t[r].ch);
		cnt_l-=s;
		cnt_r-=s;
		if(cnt_l==0) cnt_l+=t[++l].x;
		if(cnt_r==0) cnt_r+=t[--r].x;
	}
	cout<<ans;
	return 0;
}
// 10:08 AC +1h