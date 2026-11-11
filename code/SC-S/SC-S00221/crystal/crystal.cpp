#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 5 * 1e5 + 5;

long long n,m;
long long a[MAX];

bool cmp(int a,int b){ return a > b; }

void step1(){
	long long maxn = 1,prev = 0,ans = 0;
	
	sort(a + 1,a + n + 1,cmp);
	
//	for(int i = 1; i<= n;++i)	cout << a[i] << " ";
//	cout << endl;
	
	for(long long i = 1;i <= n;++i){
		long long k = prev;//上轮最大 
		ans -= (k - i + 1) * (a[i-1] - a[i]);	//在prev-i时的值 
		//cout << i<<" "<<ans << "	";
		while(ans <= m && ++k <= n){
			ans += (a[i] - a[k]);
			
			//cout << k<< ":" <<ans << " ";
		}	//第一个大于m的ans,k 
		ans -= (a[i] - a[k]);
		prev = k - 1;//k = a,ans = b
//		cout << endl;
		
//		cout << prev << " " << ans << endl;
		
		maxn = max(maxn,k - i);
	}
	
	cout << maxn;
	
	return;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(long long i = 1;i <= n;++i)	cin >> a[i];
	
	step1();
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}