#include <bits/stdc++.h>
using namespace std;
#define int long long
//zcy
const int N=200010;
int n,sum,m1,m2;
struct node{
	int l;
	char ch;
	}s[N],a[N],b[N];
int p1,p2,q1,q2; 
int zcy;
signed main()
{
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>n;
for(int i=1;i<=n;i++){
	cin>>s[i].l>>s[i].ch;
	sum+=s[i].l;
	}
sum/=2;
int tot=0;
for(int i=1;i<=n;i++){
	if(sum-tot<=s[i].l) {
		a[++m1].l=sum-tot;
		a[m1].ch=s[i].ch;
		break;
		}
	a[++m1].l=s[i].l;
	a[m1].ch=s[i].ch;
	tot+=s[i].l;
	}
tot=0;
for(int i=n;i>=1;i--){
	if(sum-tot<=s[i].l) {
		b[++m2].l=sum-tot;
		b[m2].ch=s[i].ch;
		break;
		}
	b[++m2].l=s[i].l;
	b[m2].ch=s[i].ch;
	tot+=s[i].l;
	}
p1=1;p2=1;
q1=0;q2=0;
while(p1<=m1&&p2<=m2){
	int jl=min(a[p1].l-q1,b[p2].l-q2);
	if(a[p1].ch!=b[p2].ch)
		zcy+=jl;
	q1+=jl;q2+=jl;
	if(q1>=a[p1].l){
		q1-=a[p1].l;
		p1++;
		}
	if(q2>=b[p2].l){
		q2-=b[p2].l;
		p2++;
		}
	}
cout<<zcy;
return 0;
}
