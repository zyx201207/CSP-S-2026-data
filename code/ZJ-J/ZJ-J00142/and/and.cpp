#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct stu{
	int x;
	int cnt;
	int sum;
}a[N];
bool cmp1(stu a,stu b){
	if(a.sum!=b.sum){
		return a.sum>b.sum;
	}
	if(a.x!=b.x){
		return a.x>b.x;
	}
	return a.cnt>b.cnt;
}
bool cmp2(stu a,stu b){
	if(a.cnt!=b.cnt){
		return a.cnt>b.cnt;
	}
	if(a.sum!=b.sum){
		return a.sum>b.sum;
	}
	return a.x>b.x;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		int k=a[i].x;
		while(k){
			if(k%2==1){
				a[i].cnt++;
			}
			a[i].sum++;
			k/=2;
		}
	}
	sort(a+1,a+1+n,cmp1);
	int ans1=a[1].x;
	for(int i=2;i<=m;i++){
		ans1&=a[i].x;
	}
	sort(a+1,a+1+n,cmp2);
	int ans2=a[1].x;
	for(int i=2;i<=m;i++){
		ans2&=a[i].x;
	}
	int ans=max(ans1,ans2);
	cout<<ans;
return 0;
}