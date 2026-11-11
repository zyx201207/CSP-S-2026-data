#include<bits/stdc++.h>
using gg = long long;
using namespace std;

const gg N = 5e5+5;
gg n,m,a[N],ave,cnt,i,summ,pos,ans,tot,maxx,a1,a2,a3,mm;

bool cmp(gg x,gg y){
	gg p = x - ave,q = y - ave;
	if(p * q == 0) return (p == 0) >= (q == 0);
	else return p < q; 
}

gg getLow(){
	m = mm;
	sort(a + 1,a + n + 1);
	ans = 0;
	tot = 1;
	for(i = 1;i < n;++i){
		if(a[i] == a[i + 1]) tot++;
		else tot = 1;
		ans = max(ans,tot);
	}
	return ans;
}

gg getAns1(){
	m = mm;
	ave = ceil((double)summ / n);
	
	sort(a + 1,a + n + 1);
		
	pos = upper_bound(a + 1,a + n + 1,ave) - a;
	sort(a + 1,a + pos,greater<gg>());
	sort(a + pos,a + n + 1,less<gg>());
	
	cnt = 0;
	i = 1;
	while(i <= n && m - (ave - a[i]) >= 0 && i < pos){
		m -= ave - a[i];
		cnt++;
		i++;
	}
	
	if(i == pos){
		while(i <= n && m - (i - 1) * (a[i] - ave) >= 0){
			m -= (i - 1) * (a[i] - ave);
			cnt++;
			ave = a[i];
			i++;
		}
	}
	return cnt;
}

gg getAns2(){
	m = mm;
	ave = summ / n;
	
	sort(a + 1,a + n + 1);
		
	pos = upper_bound(a + 1,a + n + 1,ave) - a;
	sort(a + 1,a + pos,greater<gg>());
	sort(a + pos,a + n + 1,less<gg>());
	
	cnt = 0;
	i = 1;
	while(i <= n && m - (ave - a[i]) >= 0 && i < pos){
		m -= ave - a[i];
		cnt++;
		i++;
	}
	
	if(i == pos){
		while(i <= n && m - (i - 1) * (a[i] - ave) >= 0){
			m -= (i - 1) * (a[i] - ave);
			cnt++;
			ave = a[i];
			i++;
		}
	}
	return cnt;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin >> n >> mm;
	for(i = 1;i <=n;++i){
		cin >> a[i];
		summ += a[i];
	}
	
	a1 = getLow();
	a2 = getAns1();
	a3 = getAns2();
	maxx = max(a1,a2);
	maxx = max(maxx,a3);
	
	cout << maxx;

	return 0;
}
