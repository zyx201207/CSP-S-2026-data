#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out.out","w",stdout);
	int n;cin>>n;
	long long a[10001][2];char c[10001];
	long long sum = 0,b_now_s=0,e_now_s=-1,b_now_z=0,e_now_z=-1;
	for(int i=0;i<n;i++) {cin>>a[i][0]>>c[i];a[i][1] = 1;}
	while(a[b_now_z][1] != 0){
		if(b_now_s>=a[b_now_z][0]) {a[b_now_z][1] = 0;b_now_z++;b_now_s=0;}
		if((0-e_now_s)>a[n+e_now_z][0]){a[n+e_now_z][1] = 0;e_now_z--;e_now_s=-1;}
		if(c[b_now_z] != c[n+e_now_z]) sum++;
		b_now_s++;
		e_now_s--;
		
	}
	sum = (sum==0? sum:sum-1);
	cout<<sum;
	return 0;
}

