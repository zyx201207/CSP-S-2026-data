#include <bits/stdc++.h>
using namespace std;
long long m,n; //  个数 && 次数
long long ln[5000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>m>>n;
	for (long long i = 0;i < m;i++){
		cin>>ln[i];
	}
	for (long long i = 0;i < n;i++){
		sort(ln,ln+n);
		ln[0] = ln[0] + 1;
	}
	int ans = 1;
	
	for (long long i = 0; i<m-1;i++){
		sort(ln,ln+n);
		if (ln[i] ==ln[i+1])ans+=1; 
	}
	cout<<ans;
	return 0;
//相加 or 数量
}
   
