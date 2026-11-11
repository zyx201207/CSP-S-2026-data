#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=1e6+10;
int cnt[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
//	system("fc and5.out and5.ans");
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int>a,x,y;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x[i]=a[i];
	} 
	sort(a.begin(),a.end());
	for(int i=1;i<=n;i++){
		int u=a[i];
		if(a[i+1]==u){
			x.clear();
			x[i]=a[i+1];
		}else{
			x[n]=a[i+1];
			cnt[i]++;
		} 
	} 
	for(int i=1;i<=n;i++){
		cout<<cnt[i]<<" ";
	} 
	return 0;
} 
