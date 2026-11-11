#include<iostream>
#define  int  long long
using namespace std;
constexpr int N=4e5+5;
bool Beg;
int n;
struct Node{
	int a; char c;
}a[N];

bool End;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].a>>a[i].c;
	int L=1,R=n,Ans=0;
	while(L<R){
		if(a[L].a<a[R].a){
			a[R].a-=a[L].a;
			if(a[L].c!=a[R].c)
				Ans+=a[L].a;
			L++;
		}else if(a[L].a==a[R].a){
			if(a[L].c!=a[R].c)
				Ans+=a[L].a;
			L++,R--;
		}else {
			a[L].a-=a[R].a;
			if(a[L].c!=a[R].c)
				Ans+=a[R].a;
			R--;
		}
	}
	cout<<Ans<<'\n';
	cerr<<(&Beg-&End)/1024.0/1024.0<<" MB\n";
	return 0;
}
