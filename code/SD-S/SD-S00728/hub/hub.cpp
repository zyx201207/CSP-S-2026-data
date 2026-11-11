#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	int t=rand()%1001+1;
	for(int i=1;i<=t;i++){
		int n=rand()%100000+1;
		cout<<n<<'\n';
	}
	return 0;
} 
//用lcy十年的rp换这道题至少骗到一个数据点（可能性几乎为0） 
