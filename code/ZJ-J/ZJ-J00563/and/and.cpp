#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	int x,y,z;
}a[200010];
int n,m;
int b[200010];
map<int,int> mp;
bool cmp(node x,node y){
	if(x.y != y.y)
		return x.y > y.y;
	return x.z > y.z;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i].x;
		mp[a[i].x]++;
		int top = 0,x = a[i].x;
		while(x){
			b[++top] = x % 2;
			x /= 2;
		}
		int y = 0,z = 0;
		for(int j = 1;j <= top;j++)
			if(b[j] == 1){
				y++;
				z = j;
			}
		a[i].y = y;
		a[i].z = z;
	}
	sort(a + 1,a + n + 1,cmp);
	int ans;
	for(int i = 1;i <= m;i++){
		if(i == 1)
			ans = a[1].x;
		else
			ans &= a[i].x;
	}
//	for(int i = 1;i <= n;i++)
//		cout << a[i].x << " " << a[i].y << endl;
	int y = 0;
	for(auto x : mp)
		if(x.second == m)
			y = max(y,x.first);
	cout << max(ans,y);
	return 0;
}