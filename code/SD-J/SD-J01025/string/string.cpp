#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
const int N=200010;
struct Info {
	int l;
	char c;
}a[N+10],z1[N+10],z2[N+10];
void debug1 (int top1,int top2) {
	printf("|debug1|:\n");
	printf("    z1:\n");
	for (int i=1;i<=top1;i++) 
		printf("%d %c\n",z1[i].l,z1[i].c);
	printf("    z2:\n");
	for (int i=1;i<=top2;i++) 
		printf("%d %c\n",z2[i].l,z2[i].c);
	printf("----------------\n");
}
int main () {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	ll len=0;
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i].l);
		cin>>a[i].c;
		len+=a[i].l;
	}
	ll qwq=len/2,ans=len/2,now=0;
	int top=1,top1=0,top2=0;
	for (;top<=n;top++) {
		if (now+a[top].l>qwq) {
			ll goal=qwq-now;
			a[top].l-=goal;
			now+=goal;
			if (goal) {
				z1[++top1].l=goal;
				z1[top1].c=a[top].c;
			}
			break;
		}
		z1[++top1]=a[top];
		now+=a[top].l;
	}
	if (len%2) a[top].l--;
//	printf("----%d----\n",now);
	now=0;
	for (;top<=n;top++) if (a[top].l) {
		z2[++top2]=a[top];
	}
	for (int i=1;i<=top2/2;i++) {
		swap(z2[i].l,z2[top2-i+1].l);
		swap(z2[i].c,z2[top2-i+1].c);
	}
//	debug1(top1,top2);
	ll num1=0,num2=0;
	int t1=0,t2=0,len1=0,len2=0;
	char last1=0,last2=0;
	while (t1<top1&&t2<top2) {
		if (num1<=num2) {
			t1++;
			if (z1[t1].c==last2) {
				ans-=min(0ll+len2,min(
				0ll+z1[t1].l,num2-num1));
			}
			num1+=z1[t1].l;
			last1=z1[t1].c;
			len1=z1[t1].l;
		}
		else {
			t2++;
			if (z2[t2].c==last1) {
				ans-=min(0ll+z2[t2].l,num1-num2);
			}
			num2+=z2[t2].l;
			last2=z2[t2].c;
			len2=z2[t2].l;
		}
	}
	while (t1<top1) {
		t1++;
		if (z1[t1].c==last2) {
			ans-=min(0ll+z1[t1].l,num2-n);
		}
		num1+=z1[t1].l;
		last1=z1[t1].c;
		len1=z1[t1].l;
	}
	while (t2<top2) {
		t2++;
		if (z2[t2].c==last1) {
			ans-=min(0ll+z2[t2].l,num1-num2);
//			printf("(%d,%d)",num1,num2);
//			printf("%lld\n",
//			min(0ll+z2[t2].l,num1-num2));
		}
		num2+=z2[t2].l;
		last2=z2[t2].c;
		len2=z2[t2].l;
	}
	printf("%lld\n",ans);
	return 0;
}
/*
4
90 y
30 h
64 t
77 y
*/
/*
9
107 w
503 o
30 j
231 z
744 b
203 i
170 n
306 v
420 i

*/ 
/*
??:?? ~ 09:39
*/
