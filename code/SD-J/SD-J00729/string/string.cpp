#include <bits/stdc++.h>
#define int long long
using namespace std;
void suio(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void fio(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
}
const int N=2e5+5;
int a[N];
char c[N];
struct node{
	int num;
	char c;
}e[N],e2[N],o[N],o2[N];
int n,sum,cur,cnt,cnt2,s,s2,ans;
signed main(){
	suio();
	fio();
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	for (int i=1;i<=n;i++){
		if(cur<=sum/2&&cur+a[i]>=sum/2){
			//split
			e[++cnt].num=sum/2-cur;
			e[cnt].c=c[i];
			break;
		}
		e[++cnt].num=a[i];
		e[cnt].c=c[i];
		cur+=a[i];
	}
	cur=0;
	for (int i=n;i>=1;i--){
		if(cur<=sum/2&&cur+a[i]>=sum/2){
			//split
			e2[++cnt2].num=sum/2-cur;
			e2[cnt2].c=c[i];
			break;
		}
		e2[++cnt2].num=a[i];
		e2[cnt2].c=c[i];
		cur+=a[i];
	}
	cur=0;
//	for (int i=1;i<=cnt;i++){
//		cout<<e[i].num<<" "<<e[i].c;
//		cout<<endl;
//	}
	int p=1,p2=1;
	s=e[p].num;
	s2=e2[p2].num;
//	cout<<cnt2;
	while (p<=cnt&&p2<=cnt2){
		if(s==0){
			s+=e[++p].num;
		}
		if(s2==0){
			s2+=e2[++p2].num;
		}
		if(e[p].c!=e2[p2].c){
			ans+=min(s,s2);
		}
		int x=min(s,s2);
//		cout<<s<<" "<<s2<<endl;
		s-=x;
		s2-=x;
	}
	cout<<ans;
	return 0;
}

