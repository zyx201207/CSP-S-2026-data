#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
//思路：把字符串折过来，看有哪些区间重叠且不相同 
//实现：先求l，然后分别求折过来后的左/右端点，之后排一下序存一下，再遍历，如果重叠且不相同ans就加上重叠区间，最后输出ans
struct node{
	int l,r;
	char c;
};
vector<node> a;
bool cmp(node a,node b){
	return a.l<=b.l;
}
struct in{
	int l,r;
	char c;
};
vector<in> asd;
ll l=0;
ll ans;
int n;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int l1;
		char c;
		cin>>l1>>c;
		in qqq;
		qqq.l=l+1;
		qqq.r=l+l1;
		qqq.c=c;
		asd.push_back(qqq);
		l+=l1;
	}
	int mid;
	if(l%2==0){
		mid=l/2;
	}else{
		mid=l/2+1;
	}
	for(auto i:asd){
		int l1=i.l;
		int r1=i.r;
		char c=i.c;
		if(l1<=mid&&r1>mid){
			if((l-r1+1)<=l1) a.push_back({(l-r1+1),mid,c});
			else a.push_back({l1,mid,c});
		}else{
			if(l1>mid){
				l1=l-l1+1;
			}
			if(r1>mid){
				r1=l-r1+1;
			}
			a.push_back({min(l1,r1),max(l1,r1),c});
		}	
	}
	sort(a.begin(),a.end(),cmp);
	bool fla=0;
	bool youren=0;
	node now;
	for(auto i:a){
		if(youren==0){
			now=i;
			youren=1;
		}
		if(now.c!=i.c){
			ans+=max(min(now.r,i.r)-max(now.l,i.l)+1,0*1ll)*1ll;
		}
		if(now.r<i.r){
			now=i;
		}
	}
	cout<<ans;
	return 0;
}


