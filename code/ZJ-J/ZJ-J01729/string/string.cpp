#include<bits/stdc++.h>
using namespace std;
struct STR {
	int num;
	char a;
};
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	STR str[n+1];
	STR hw[n+1];
	long long s=0;
	for(int i=1; i<=n; i++) {
		int x;
		char o;
		cin>>x>>o;
		s+=x;
		str[i].num=x;
		str[i].a=o;
		hw[n-i+1].num=x;
		hw[n-i+1].a=o;
	}
	long long sum=0;
	int str_i=1;
	int hw_i=1;
	while(s>0) {
		int y=min(str[str_i].num,hw[hw_i].num);
		if(str[str_i].a!=hw[hw_i].a) {
			sum+=y;
		}
		s-=y;
		str[str_i].num-=y;
		hw[hw_i].num-=y;
		if(str[str_i].num==0){
			str_i++;
		}
		if(hw[hw_i].num==0){
			hw_i++;
		}
	}
	cout<<sum/2;
	return 0;
}
