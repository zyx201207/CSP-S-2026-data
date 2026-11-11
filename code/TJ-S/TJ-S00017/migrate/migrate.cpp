#include <bits/stdc++.h>
using namespace std;

#define LL long long

LL c,t;
LL x[2000005];

bool solve(LL start,LL finished,LL step){
	return (finished - start) / step % 2;
}

int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	for(int i = 1;i <= t;i++){
		LL n,d,sum = 0;
		cin>>n>>d;
		for(int j = 1;j <= n;j++){
			cin>>x[j];
		}
		for(int j = n + 1;j <= 2000000;j++){
			if(x[j] == 0) break;
			x[j] = 0;
		}
		for(LL start = 1;start < n;start++){
			for(LL finished = start + 1;finished <= n;finished++){
				if(solve(start,finished,d)) sum++;
			}
		}
		cout<<abs(n - sum)<<endl;
	}
	
	return 0;
}
