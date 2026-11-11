#include<bits/stdc++.h>
#define int long long
#define fileio
//#define opensync
//#define multicase
using namespace std;
int n,m,a[500005],s,ans; 
void INIT(){
	
}
void MAIN(int CASE){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int i=0,j=0;
	while(j<n-1){
		while(j<n-1&&s+(a[j+1]-a[j])*(j-i+1)<=m){
			j++;
			s+=(a[j]-a[j-1])*(j-i);
		}
		ans=max(ans,j-i+1);
		s-=a[j]-a[i];
		i++;
	}
	cout<<ans;
}
signed main(){
#ifndef opensync
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
#ifdef fileio
	ifstream fin("crystal.in");
	ofstream fout("crystal.out");
	auto oldcin=cin.rdbuf(fin.rdbuf());
	auto oldcout=cout.rdbuf(fout.rdbuf());
#endif
	int t=1;
#ifdef multicase
	cin>>t;
#endif
	INIT();
	for(int i=0;i<t;i++){
		MAIN(i);
	}
#ifdef fileio
	cin.rdbuf(oldcin);
	cout.rdbuf(oldcout);
#endif
	return 0;
}
/*
Trick||Treat! 

Oct31==Dec25?

注意到肯定是一段连续区间被操作
直接双指针 

14:44
很好过了大样例，对拍等打完T2再说 

16:39
WA on: 
3 7
5 0 1 
有点神秘 
*/
