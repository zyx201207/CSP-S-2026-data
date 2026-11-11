#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],q[500005],head = 1,tail = 1,cnt[300005];
bool check(int x){
	for (int i = head;i <= tail;i++){
		if (q[i] == x) return false;
	}
	return true;
}
int f(int x){
	for (int i = head;i <= tail;i++){
		if (q[i] == x) return i;
	}
	return -1;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i = 1;i <= n;i++) cin>>a[i];
    for (int i = 1;i <= n;i++){
		while (head != tail) q[tail--] = 0;
		head = 1,tail = 1;
		for (int j = i;j <= n;++j){
			if (head == tail || check(a[j])) q[tail++] = a[j];
			else{
				int g = f(a[j]);
				for (int k = head;k <= g;k++) q[k] = 0;
				head = 1,tail = 2;
				q[head] = a[j];
			}		
		}
		for (int j = head;j <= tail;j++){
			cnt[q[j]]++;
		}
	}
	for (int i = 1;i <= m;i++) cout<<cnt[i]<<' ';
    return 0;
}
