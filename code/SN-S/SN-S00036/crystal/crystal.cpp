#include<bits/stdc++.h>
using namespace std;

long long n,m;//n个水晶，m次操作
long long a[500010];
int ans = 1;

long long sum[500010];

int L,R,mid;

bool check(int len,int i) {
	bool F = ((len - 1) * a[i] - (sum[i - 1] - sum[i - len])) <= m;
//	cout<<"CHECK！减少量为"<<((len - 1) * a[i] - (sum[i - 1] - sum[i - len]))<<endl;
	return F;
}

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i = 1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i<=n;i++) {
		sum[i] = sum[i-1] + a[i];
	}
	//开始主体代码 
	for(int i = 1;i<=n;i++) {
//		cout<<"正在处理数据"<<i<<endl;
		//我要用二分求len。
		//我要求len，使(len - 1) * a[i] - (sum[i - 1] - sum[i - len])恰好<m（即临界<m）
		//可以证明这个式子单调递增，即草稿纸上②
		//我要让L = 1,R = i。len = mid，check检查式子是否大于m。
		//如果大于m，返回0，调整右端点 = mid - 1；小于m，返回1，调整左端点 = mid，直到L = R 
		L = 1,R = i;
		
		
		while(L < R) {
			mid = ((L + R)>>1) + 1;
//			cout<<"二分中！！！此时L："<<L<<"，R:"<<R<<"，mid，即len为："<<mid<<endl;
			if(check(mid,i)) {
				L = mid;
//				cout<<"调整左端点！"<<endl;
			}
			else {
				R = mid - 1;
//				cout<<"调整右端点！"<<endl;
			}
				
		}
		
//		cout<<"====================="<<endl<<"当次处理，len为"<<mid<<"，ans为"<<ans<<endl<<endl;
		ans = max(ans,R);
	}
	cout<<ans;
	return 0;
} 
