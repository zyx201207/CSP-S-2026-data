#include<bits/stdc++.h>
using namespace std;
#define int long long
//十年OI一场空,不开________见祖宗 
//#define endl '/n'
/*
第一眼看上去
贪心orDP?
可以发现,如果把每个数都转成二进制,由于必须恰好m个数,可以考虑按1的位置排序
也就按每一位是1还是0先后排序
但这样显然是不对的,例如：
3 2
10000000000 01111111111 1111111111 (2)
诶好像有点对,不如写出来测测大样例
0000000000000000000001000000000
0000000000000000000000111111111
被劲爆的构造卡了5555
还是想DP吧 
dp[i][j]表示考虑第i个数,j=0时这个数不选,j=1时这个数选
那怎么转移呢???
可以发现n是2e5
出题人明显想让我们写O(n)或者O(nlogn) 
去看第四题没时间了
直接交吧,特殊性质B应该有分 
这个表好像不准,还能打个暴力
好像是我记错时间了OWO 
期望25~35
*/
int n,m,a[55],ans=0;
void dfs(int x,int y,int sum,bool k){//考虑到第x个数,选了y个,当前和为sum,第x个数选不选 
	if(sum<=ans){
		return;//神秘小剪枝,不过应该快不了多少 
	} 
	if(x==n+1){
		if(y==m){
			ans=max(ans,sum);
		}
		return;
	}
	dfs(x+1,y+1,sum&a[x],1);//这个数不选 
	dfs(x+1,y,sum,0);//这个数选 
}
vector<pair<int,string>> v;//first是原数 
bool cmp(pair<int,string> x,pair<int,string> y){	
	return x.second>y.second;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int sum=0;
	cin>>n>>m;
	if(n<=50){//小数据暴力 
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ans=0;
		dfs(0,0,(1<<30)-1,0);
		cout<<ans;
		return 0;
	}
	//大数据使用不太正确的正解 
	for(int i=1;i<=n;i++){
		int x,xx;
		cin>>x;
		xx=x;
		string s="";
		//转二进制 
		while(x){
			s+=char(x%2+'0');
			x/=2;
		}
		reverse(s.begin(),s.end());
//		cout<<s<<" ";
		if(s.size()<30){
			for(;s.size()<=30;){
				s="0"+s;//补齐不足30位 
			}
		}
		v.push_back(make_pair(xx,s));
	}
	sort(v.begin(),v.end(),cmp);//直接按字典序从大到小即可 
//	for(auto kun:v){//调试不删,警钟敲烂 
//		cout<<kun.second<<endl;
//	}
	int ans=v[0].first;
	for(int i=0;i<m;i++){
//		cout<<v[i].second<<endl;
		ans&=v[i].first;
	}
	cout<<ans;
	return 0;
}
