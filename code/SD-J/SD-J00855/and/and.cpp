#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct data{
	int mx;
	int hi;
	int num;
};
data chai(int a){
	data ans;
	ans.num=a;
	int cnt=0;
	int cnt2=0;
	while(a!=0){
		if(a&1){
			cnt++;
		}
		cnt2++;
		a>>=1;
	}
	ans.hi = cnt2;
	ans.mx=cnt;
	return ans; 
}
bool cmp1(data a, data b){
	return a.hi > b.hi;
}
bool cmp2(data a, data b){
	return a.mx > b.mx;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<data> a(n);
	for(int i =0;i<n;i++){
		int c;
		cin>>c;
		a[i]=chai(c);
	}
	vector<data> b(n);
	b=a;
	sort(a.begin(),a.end(),cmp1);
	sort(b.begin(),b.end(),cmp2);
	int ans=0;
	int tmp1=a[0].num;
	int tmp2 = b[0].num;
	for(int i =1;i<m;i++){
		tmp1 = max(tmp1&a[i].num,tmp1&b[i].num);
	}
	for(int i =1;i<m;i++){
		tmp2 = max(tmp2&a[i].num,tmp2&b[i].num);
	}
	ans = max(tmp1,tmp2);
	cout<<ans<<endl;
	return 0;
}
