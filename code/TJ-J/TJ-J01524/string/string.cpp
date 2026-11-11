#include <bits/stdc++.h>
using namespace std;

struct wen{
	long long a;
	char c;
};

wen b[200005],q[200005],h[200005],b_1[200005];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n = 0;
    long long all = 0;
    cin >> n;
    for (long long i = 1;i <= n;i++){
    	cin >> b_1[i].a;
    	cin >> b_1[i].c;
    	all += b_1[i].a;
	}
	long long bk = 1;
	long long da = b_1[1].a;
	char dc = b_1[1].c;
	for (long long i = 2;i <= n + 1;i++){
		if (b_1[i - 1].c == b_1[i].c){
			dc = b_1[i].c;
			da += b_1[i].a;
		}
		else{
			b[bk].a = da;
			b[bk].c = dc;
			bk++;
			da = b_1[i].a;
			dc = b_1[i].c;
		}
	}
	if (bk == 2){
		cout << 0;
		return 0; 
	} 
	long long qn = all / 2,hn = all / 2;
	long long qk = 1,hk = 1;
	for (long long i = 1;i < bk;i++){
		if (b[i].a <= qn){
			q[i].a = b[i].a;
			qn -= b[i].a;
			b[i].a = 0;
			q[i].c = b[i].c;
		}
		else{
			q[i].a = qn;
			b[i].a -= qn;
			qn = 0;
			q[i].c = b[i].c;
		}
		if (!qn){
			qk = i;
			break;
		}
	}
	for (long long i = bk - 1;i >= 1;i--){
		if (b[i].a <= hn){
			h[bk - i].a = b[i].a;
			hn -= b[i].a;
			b[i].a = 0;
			h[bk - i].c = b[i].c;
		}
		else{
			h[bk - i].a = hn;
			b[i].a -= hn;
			hn = 0;
			h[bk - i].c = b[i].c;
		}
		if (!hn){
			hk = bk - i;
			break;
		}
	}
	long long diff = 0;
	long long qh = 1,hh= 1;
	while (qh <= qk && hh <= hk){
		long long a_1 = min(q[qh].a,h[hh].a);
		q[qh].a -= a_1;
		h[hh].a -= a_1;
		if (q[qh].c != h[hh].c){
			diff += a_1; 
		}
		if (q[qh].a == 0){
			qh++;
		}
		if (h[hh].a == 0){
			hh++;
		}
	}
	cout << diff;
    return 0;
}

