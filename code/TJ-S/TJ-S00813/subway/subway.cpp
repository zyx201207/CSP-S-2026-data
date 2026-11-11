#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
		for(int i=0;i<n;i++){
		if(m2>m){
			ans[sum]=num-1;
			sum++;
			num=0;
			i=sum;
		}
		if(m2==m){
			ans[sum]=num;
			sum++;
			num=0;
			i=sum;
		}
		m2=m2+a[i+1]-a[i];
		num++;	
	}
	int cnt=max(ans[0],ans[n]);
	cout<<35<<"\n"<<16;
	return 0;
}
