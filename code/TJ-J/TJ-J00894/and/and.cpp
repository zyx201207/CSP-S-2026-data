#include<bits/stdc++.h>
using namespace std;
struct ints{
	int ten;
	int num_of_1;
};
int ten_to_bin(int n){
	string ans="";
	int m=0;
	while(n){
		m+=n%2;
		ans+=(n%2)+'0';
		n/=2;
	}
//	reverse(ans.begin(),ans.end());
	return m;
}
bool cmp(ints a,ints b){
	return a.num_of_1>=b.num_of_1;
}
int n,m;
ints a[200009];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i].ten;
		a[i].num_of_1=ten_to_bin(a[i].ten);
	}
	sort(a,a+n,cmp);
	int ans=a[0].ten;
	for(int i=1;i<m;i++){
		ans=(ans&a[i].ten);
	}
	cout<<ans;
	return 0;
}
//wei yun suan NB!!!!
//wei yun suan yyds!!!
//wei yun suan easy!!!
