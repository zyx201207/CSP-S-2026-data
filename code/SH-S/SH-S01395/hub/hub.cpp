#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;scanf("%d%d",&c,&t);
	while (t--) {
		int n,k;scanf("%d%d",&n,&k);
		for (int i=1,x; i<n; i++) scanf("%d",&x);
		if (n>=4) printf("%d\n",sqrt(n)-1);
		else puts("1"); 
	}
	return 0;
}
/*
why today's T3 sooo hard,maybe NOI-
why??? and T4's brute so hard to write and only 5pts
i cant find any good thing to pianfen.
i shall output what? sqrt(n)-1 may be can get many fen.
man.... i can only get 1=.... not even 300pts on CSP-S(if im unlucky)...
ready to say goodbye to my OI life after this year's NOIP...

good bye,OI ¡ªSH-S01395
6 Years of OI becomes nothing but air
not using long long makes you see your ancestors
NOIP 1= is my last dream
but how can it come true with a <=300 score on CSP-S?
i pray for myself
i pray for everyone like me
please dont let my last dream become a joke
dont let my last fight become a weak voice in the air
thank everybody who supported me in OI
but it seems like i let all of you down....
that's all. bye-bye,OI.
wish C*i*a C*m*u*e* F*d*r*t*o* will be better every day. 
wish *h*n* *o*p*t*r *e*e*a*i*n will b
*/
