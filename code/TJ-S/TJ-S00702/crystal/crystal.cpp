#include<bits/stdc++.h>
using namespace std;
long long n,m,mn,nm;
struct arr{
	long long p;
	long long cha;
};
arr a[100000];
bool cmp(arr b,arr c){
	if(max(b.p,mn)-min(b.p,mn)==max(c.p,mn)-min(c.p,mn)){
		return b.p>c.p;
	}else{
		return max(b.p,mn)-min(b.p,mn)<max(c.p,mn)-min(c.p,mn);
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i].p;
		mn+=a[i].p;
	}
	mn/=n;
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		a[i].cha=max(a[i].p,a[0].p)-min(a[i].p,a[0].p);
		if(a[i].cha<=m){
			nm++;
			m-=a[i].cha;
		}
	}
	cout<<nm;
	return 0;
} 
