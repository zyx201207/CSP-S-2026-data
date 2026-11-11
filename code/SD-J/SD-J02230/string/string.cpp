#include<bits/stdc++.h>
using namespace std;
struct node{
	long long gs;
	char a;
};
long long n, num[200004], ans, m, a_i = 1, a_ii = 1;
char aaa[200004];
queue<int> legs, rigs;
queue<char> lea, ria;
int main() {
	freopen("string.in","r", stdin);
	freopen("string.out","w", stdout);
	cin >> n;
	for (int i = 1; i<=n ;i++) {
		scanf("%d", &num[i]); 
		getchar();
		scanf("%c", &aaa[i]);
		m+=num[i];
	}
	legs.push(num[1]);
	rigs.push(num[n]);
	lea.push(aaa[1]);
	ria.push(aaa[n]);
	for (long long i = 0; i <= m/2; ) {
		node les;
 		node ris;
 		if (legs.empty()) {
 			legs.push(num[++a_i]);
			lea.push(aaa[a_i]);
		}
		if (rigs.empty()) {
			a_ii++;
			rigs.push(num[n-a_ii+1]);
			ria.push(aaa[n-a_ii+1]);
		}
 		les.gs = legs.front();
 		legs.pop();
 		les.a = lea.front();
 		lea.pop();
 		
 		ris.gs = rigs.front();
 		rigs.pop();
 		ris.a = ria.front();
 		ria.pop();
 		if (les.gs > ris.gs) {
 			if (les.a != ris.a) {
 				ans+=ris.gs;
			}
			i+=ris.gs;
			lea.push(les.a);
			legs.push(les.gs-ris.gs);
		} else if (les.gs < ris.gs) {
			if (les.a != ris.a) {
 				ans+=les.gs;
			}
			i+=les.gs;
			ria.push(ris.a);
			rigs.push(ris.gs-les.gs);
		} else {
			i+=les.gs;
			if (les.a != ris.a) {
 				ans+=les.gs;
			}
		}
	}
	cout << ans;
	return 0;
} 
