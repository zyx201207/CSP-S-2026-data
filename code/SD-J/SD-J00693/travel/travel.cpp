#include <bits/stdc++.h>
using namespace std;

int	a,b;
char c,d; 
int n,m;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out ","w",stdout);
	
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> a >> n >> c >> b >> m >> d;
	int ans1,ans2,ans3,ans4;
	
	if(a == b) 
		ans1 = 1;
	else 
		ans1 = 0;
	
	if(ans1 && n == m)
		ans2 = 1;
	else
		ans2 = 0;
	
	if(ans2 == 1 && ((c >= 'D' && d >= 'D')||(c <= 'C' && d <= 'C'))){
		ans3 = 1;
	}else{
		ans3 = 0;
	}
	
	if(ans3 && abs(c - d) == 1)
		ans4 = 1;
	else
		ans4 = 0;
	
	cout << ans1 << ans2 << ans3 << ans4;
	
	return 0; 
}
// Trick||Treat!
