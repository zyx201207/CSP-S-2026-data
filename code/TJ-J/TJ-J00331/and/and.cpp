#include<bits/stdc++.h>
using namespace std;
struct sd{
	int a = 0;
	int lj = 0;
}; 
int i,j,n,m,tp,ans;
int slj[31] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
sd a[200010];

bool cmp(const sd& aa,const sd& bb){
	if(aa.lj != bb.lj){
		return aa.lj < bb.lj;
	}
	return aa.a > bb.a;
}

int main(){
	freopen("and5.in","r",stdin);
	//freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	//O(31n)
	for(i = 1;i <= n;i++){
		cin >> tp;
		a[i].a = tp;
		for(j = 1;j < 31;j++){
			if(tp <= slj[j]){
				a[i].lj = j;
				continue;
			}
		}
	}
	//O(n logn)
	sort(a+1,a+n+1,cmp);
//	ans = a[1].a;
//	cout <<a[1].a<<endl;
//	for(i = 2;i <= m;i++){
//		cout << "ans&" << a[i].a;
//		ans = ans & a[i].a;
//		cout << "  = " << ans << endl;
//	}
	int ans1 = -1;
	int c = 1;
	for(i = 1;i <= n;i++){
		if(a[i].lj == a[i-1].lj){
			if(ans1 == -1) ans1 = a[i].a & a[i-1].a;
			else ans1 = ans1&a[i].a;
			if(c == m){
				break;
			}
			c++;
		}else{
			c = 1;
			ans1 = -1;
		}
	}
	ans = a[1].a;
	for(i = 2;i <= m;i++){
		ans = ans & a[i].a;
	}
	cout << max(ans,ans1);
	return 0;
}
