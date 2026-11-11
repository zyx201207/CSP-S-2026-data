#include<bits/stdc++.h>
#define ll long long
#define pr priority_queue
#define F first
#define endl "\n"
#define S second
#define pi pair
#define mk make_pair
#define ull unsigned long long
using namespace std;
const int N=2e5+100;
int a[N];
int n,m;
bool cmp(int a,int b){
	return a>b;
}
void solve1(){
	sort(a+1,a+1+n,cmp);
	cout<<a[1];
	return ;
}
void solve2(){
	sort(a+1,a+1+n,cmp);
	vector<int> g[31];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=30;j++){
			if((a[i]>>(j-1))&1){
				g[j].push_back(a[i]);
			}
		}
	}
	int ans=0;
	for(int i=30;i>=1;i--){
		if(g[i].size()>m){
			ans=g[i][0];
			for(int j=1;j<m;j++){
				ans=ans&g[i][j];
			}break;
		}
	}
	cout<<ans;
}
int main(){
//	system("fc and.out and4.ans");
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	} 
	if(m==1){
		solve1();
	}
	else{
		solve2();
	}
	return 0;
}

