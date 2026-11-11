#include<bits/stdc++.h>
using namespace std;
long long cjj_a[500005],cjj_b[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long int cjj_n,cjj_m;
	cin>>cjj_n>>cjj_m;
	for(unsigned long long int i=1;i<=cjj_n;i++){
		cin>>cjj_a[i];
	}
	sort(cjj_a+1,cjj_a+cjj_n+1);
	for(unsigned long long int i=2;i<=cjj_n;i++){
		cjj_b[i]=cjj_a[i]-cjj_a[i-1];
	}
	unsigned long long int chenchenkx=cjj_m,cjj_pp=1,cjj_now=2,cjj_max=-1;
	for(unsigned long long int i=1;i<=cjj_n;i++,cjj_now++){
		while(chenchenkx>=cjj_b[cjj_now]*cjj_pp&&cjj_now<=cjj_n){
			chenchenkx-=cjj_b[cjj_now]*cjj_pp;
			cjj_now++;
			cjj_pp++;
			cout<<chenchenkx<<endl;
		}
		cjj_max=max(cjj_pp,cjj_max);
		chenchenkx+=cjj_b[cjj_now]-cjj_b[i];
		cjj_pp--;
	}
	cout<<cjj_max;
	return 0;
}
