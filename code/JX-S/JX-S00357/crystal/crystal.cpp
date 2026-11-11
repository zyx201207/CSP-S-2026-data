#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 5e5+10;
LL a[N],n,m;
LL tree[4*N];
void build(int idx,int l,int r){
	//cerr << "l=" << l << " r=" << r << " idx=" << idx << "\n";
	
	if(l == r){
		tree[idx] = 0;
		return;
	}
	int mid = (l+r)/2;
	build(idx*2,l,mid);
	build(idx*2+1,mid+1,r);
	tree[idx] = tree[idx*2]+tree[idx*2+1]+(a[r]-a[mid])*(mid-l+1);
}
LL gt(int idx,int l,int r,int l1,int r1){
	//cerr << "idx=" << idx << " l=" << l << " r=" << r << " l1= << "\n";
	if(l == l1 && r == r1){
		return tree[idx];
	}
	int mid = (l+r)/2;
	if(r1 <= mid){
		return gt(idx*2,l,mid,l1,r1);
	}
	if(l1 > mid){
		return gt(idx*2+1,mid+1,r,l1,r1);
	}
	LL lsd = gt(idx*2,l,mid,l1,mid),rsd = gt(idx*2+1,mid+1,r,mid+1,r1);
	return lsd+rsd+(a[r1]-a[mid])*(mid-l1+1);
}
bool check(int w){
	for(int l = 1,r = w;r <= n;l++,r++){
		if(gt(1,1,n,l,r) <= m){
			//cerr << "l=" << l << " r=" << r << " gets=" << gt(1,1,n,l,r) << "\n";
			return true;
		}
	}
	return false;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	
	//int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	
	build(1,1,n);
	
	int l = 1,r = n,ans = 1;
	while(l <= r){
		int mid = (l+r)/2;
		if(check(mid)){
			ans = mid;
			l = mid+1;
		} else{
			r = mid-1;
		}
	}
	cout << ans;
	return 0;
}
