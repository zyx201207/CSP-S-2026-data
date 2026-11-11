#include<bits/stdc++.h>
#define int long long
const int N=2e5+10,M=110;
using namespace std;
string s[N];
int n,m;
bool op[N];
int a[N];
int  check(int x){
	int cnt=0;
	for (int i=0;i<n;i++){
	if (s[i][x]=='1'&&op[i])cnt++;	
	}
	return cnt;
}
void qing(int x){
	for (int i=0;i<n;i++){
	if (s[i][x]!='1')op[i]=false;	
	}
}
void solve(){
    cin>>n>>m; 
    for (int i=0;i<n;i++){
    int x;
	cin>>x;
	s[i]="";
	while (x){
	s[i]+=(x%2)+'0';
	x/=2;	
	}
	for (int j=0;j<s[i].size();j++){
	a[j]+=s[i][j]-'0';	
	}	
	}
	for (int i=0;i<n;i++){
	op[i]=true;	
	}
	int lxy=-1;
	for (int i=40;i>=0;i--){
	if (a[i]>=m){
	lxy=i;	
	break;	
	}
	}
	if (lxy==-1){
	cout<<"0";
	return ;	
	}
	vector<int>v;
	v.clear();
	for (int i=lxy;i>=0;i--){
	if (check(i)>=m){
	v.push_back(i);	
	qing(i);	
	}
	}
	int anss=0;
	for (auto t:v){
	anss+=(1<<t);
	}
	cout<<anss;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int T=1;
//	cin>>T;
	while (T--)solve();
	return 0;
}

