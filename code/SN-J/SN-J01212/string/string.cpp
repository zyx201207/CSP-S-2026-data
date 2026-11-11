#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+7;
int n,idx,idx_r;
struct Node{
	ll a,p;
	char c;
}g[N];
ll sum,r,cha;
//bool flag=false;
ll ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>g[i].a>>g[i].c;
		g[i].p=g[i].a+g[i-1].p;
	}
	sum=g[n].p;
	
	if(sum%2==1){//奇数
		sum=sum/2+1;
	}else sum/=2;
	
	idx=1,idx_r=n;
	r=g[idx_r].p;
	while((r-g[idx_r].a)>=sum){
		cha=g[idx_r].a-g[idx].a;
		if(cha==0){
			if(g[idx_r].c==g[idx].c){
				r-=g[idx_r].a;
				idx_r--;idx++;
			}else{//g[idx_r].c!=g[idx].c
				ans+=g[idx_r].a;
				r-=g[idx_r].a;
				idx_r--;idx++;
			}
		}else if(cha>0){//r大 
			if(g[idx_r].c==g[idx].c){
				r-=g[idx_r].a+cha;
				g[idx_r].a-=cha;
				idx++;
			}else{//g[idx_r].c!=g[idx].c
				ans+=g[idx_r].a-cha;
				r-=g[idx_r].a+cha;
				g[idx_r].a-=cha;
				idx++;
			}
		}else{//左边大 
			if(g[idx_r].c==g[idx].c){
				r-=g[idx_r].a;
				g[idx].a+=cha;
				idx_r--;
			}else{//g[idx_r].c!=g[idx].c
				
				ans+=g[idx_r].a;
				r-=g[idx_r].a;
				g[idx].a+=cha;
				idx_r--;
			}
		}
	}
	if((r-g[idx_r].a)<sum){//r多 
		for(;idx<idx_r;idx++){
			if(g[idx_r].c!=g[idx].c) ans+=g[idx].a;
			idx++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
/*
3
2 a
2 b
1 c
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
