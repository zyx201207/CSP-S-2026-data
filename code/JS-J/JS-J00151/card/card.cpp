#include <bits/stdc++.h>
using namespace std;
int n,num,a[300005],oldn,cnt,sum,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	while(n--){
		cin >> num;
		if(num!=oldn){
			a[oldn]=cnt;
			cnt=0;
			oldn=num;
		}
		cnt++;
	}
	a[num]=cnt;
	for(int i=1;i<=m;i++){
		sum+=a[i];
		cout << sum << ' ';
	}
	return 0;
}
