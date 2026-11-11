#include<bits/stdc++.h>
#define int long long

using namespace std;
int n,a[500100],m,ans=1,now=1,bg=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		m-=((i-bg)*(a[i]-a[i-1]));
		now++;
		if(m<0){
			int j=bg;
			while(m<0){
				m+=(a[i]-a[j]);
				j++;
				now--;
			}
			bg=j;
		}
		ans=max(ans,now);
	}cout<<ans;
	return 0;
}
// zhe ge ji fang hao ** re(A401)
// wc wo hao xiang zuo chu lai le --14:45
// kao, yang li 4 mei guo --14:47
// wen ti chu zai mei ci jia jian m de shi hou,
// dou cong 1 kai shi suan
// all AC --15:02

