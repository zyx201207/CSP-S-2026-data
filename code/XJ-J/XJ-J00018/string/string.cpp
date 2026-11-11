#include <bits/stdc++.h>
using namespace std;

struct node{
	int num;
	char c;
}a[200005];
int main(){
	freopen("string.in ","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i].num >> a[i].c;
	int l = 1,r = n;
	long long cnt = 0;
	while(l < r){
		if(a[l].c != a[r].c){
			int minn = min(a[l].num,a[r].num);
			cnt += minn;
			a[l].num -= minn;
			a[r].num -= minn;
			if(a[l].num == 0) l++;
			if(a[r].num == 0) r--;
		}else{
			int minn = min(a[l].num,a[r].num);
			a[l].num -= minn;
			a[r].num -= minn;
			if(a[l].num == 0) l++;
			if(a[r].num == 0) r--;
		}
	}
	cout << cnt;
	return 0;
}

