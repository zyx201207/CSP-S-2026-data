#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int cjj_n,cjj_m;
	cin>>cjj_n>>cjj_m;
	int cjj_a[200005];
	for(int i=1;i<=cjj_n;i++){
		cin>>cjj_a[i];
	}
	if(cjj_m==1){
		sort(cjj_a+1,cjj_a+1+cjj_n);
		cout<<cjj_a[cjj_n];
		return 0;
	}
	if(cjj_m==cjj_n){
		int cjj_num=cjj_a[1];
		for(int i=2;i<=cjj_n;i++){
			cjj_num&=cjj_a[i];
		}
		cout<<cjj_num;
		return 0;
	}
	sort(cjj_a+1,cjj_a+1+cjj_n);
	int cjj_num=cjj_a[cjj_n];
	for(int i=1;i<=cjj_m;i++){
		cjj_num&=cjj_a[cjj_n-i];
	}
	cout<<cjj_num;
	return 0;
}
