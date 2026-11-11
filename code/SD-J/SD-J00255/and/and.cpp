#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<stack>
#include<climits>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#define endl '\n'
using namespace std;
const int MAXN=2e5+7;
int a[MAXN];
int flag , mx;
int main(){
	ios::sync_with_stdio(nullptr);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	mx=a[n-1];
	for(int i=n-1;i>n-m;i--){
		mx&=a[i];
	}cout<<mx;
	return 0;
}
