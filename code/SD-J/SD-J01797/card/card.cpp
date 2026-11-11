#include <bits/stdc++.h> 
using namespace std;
long long n,m,a[201000];
string s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long i,x,b,j,cnt1 = 0,cnt2 = 0;
	cin>>n>>m;
	for(i = 0;i < n;i ++){
		cin>>a[i];
	}
	while(n--){
		for(i = 0;i < n;i ++){
			x = s.find(a[i]);
			if(x) s.erase(x);
			s[i] = a[i];	
		}
		for(i = 0;i <= n;i ++){
			b = s[i] - 'A' + '0';
			if(b == 1) cnt1++;
			if(b == 2) cnt2++;
		}
		for(i = 0;i < n;i ++){
			s[i] = '0';
		}
	}
	cout<<cnt1<<cnt2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
