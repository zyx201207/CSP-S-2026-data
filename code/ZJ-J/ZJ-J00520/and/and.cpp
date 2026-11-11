#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
const int N=2e5+5;
int n,m;
int a[N];
int cnt[N],Ans;
bool check(int mid){
	vector<int>id;
	int c=0,x=0;
	while(mid){
		if(mid&1){
			c++;
			id.push_back(1<<x);
		}
		mid>>=1;
		x++;
	}
	for(int i=1;i<=n;i++)cnt[i]=0;
	for(int i=0;i<id.size();i++){
		for(int j=1;j<=n;j++){
			if(a[j]&id[i]){
				cnt[j]++;
			}
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		if(cnt[i]==c){
			sum++;
		}
	}
	return sum>=m;
} 
void dfs(int pos,int sum,int choose){
	if(choose==m){
		Ans=max(Ans,sum);
		return ;
	}
	if(pos>n)return ;
	if(sum==-1){
		dfs(pos+1,a[pos],choose+1);
		dfs(pos+1,sum,choose);
	}
	else{
		dfs(pos+1,sum&a[pos],choose+1);
		dfs(pos+1,sum,choose);
	}
}
void work1(){
	int mx=0;
	for(int i=1;i<=n;i++){
		mx=max(mx,a[i]);
	}
	cout<<mx;
} 
void work2(){
	int mx=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			mx=max(mx,a[i]&a[j]);
		}
	}
	cout<<mx;
}
void work3(int mx){
	for(int i=mx;i>=0;i--){
		if(check(i)){
			cout<<i;
			return ;
		}
	} 
}
void solve(){
	cin>>n>>m;
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(n<=20){
		dfs(1,-1,0);
		cout<<Ans;
		return ;
	}
	else if(n<=2000&&m==1){
		work1();
		return ;
	}
	else if(n<=2000&&m==2){
		work2();
		return ;
	}
	else if(mx*n*20<=200000000){
		work3(mx);
		return;
	}
	else{
		sort(a+1,a+n+1);
		int l=0,r=mx,ans=0,mid;
	//	cout<<check(16)<<" ";
		while(l<r){
			mid=l+r+1>>1;
	//		cout<<mid<<" ";
			if(check(mid)){
				l=mid;
	//			ans=mid; 
			}
			else{
				r=mid-1;
			}
		}
		ans=l;
		l=1,r=n,mid=0;
		int ans1=0;
		while(l<r){
			mid=l+r+1>>1;
			if(check(a[mid])){
				l=mid;
	//			ans1=a[mid];
			}
			else{
				r=mid-1;
			}
		} 
		ans1=a[l];
		cout<<max(ans1,ans)<<"\n";
	}
} 

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//	system("fc and.out and5.ans");
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}
/*
可以考虑二分一个最大值

这个答案只在一定条件下具备单调性

每次二分一个答案 

枚举mid每一位为1的位置，
然后去原数组中找这一位为1的个数，
统计一个cnt数组 
最后判断cnt为__builtin_popcount(mid)的位置是否>=m个即可 
2e5*20*30

[55-100]pts

20
10 
234 1235324 2349 32401 2349
12342
234
1242
123292
1239723
1298732
1203
123
345
234
298
230498
23987
899
393
*/
