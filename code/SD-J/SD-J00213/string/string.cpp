#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
/*####################*/
using lnt=long long;
const int N=2e5+10;
/*####################*/
struct node{
	int a;
	char c;
}b[N];
/*####################*/
void Solve(void){
	int n;cin>>n;
	lnt sum;
	for(int i=1;i<=n;i++){
		cin>>b[i].a>>b[i].c;
		sum+=b[i].a;
	}int L,R;
	L=1,R=n;
	lnt ans=0;
	while(L<R){
		ans+=min(b[L].a,b[R].a)*(b[L].c!=b[R].c);
		if(b[L].a>b[R].a){
			b[L].a-=b[R].a;
			R--;
		}else if(b[L].a<b[R].a){
			b[R].a-=b[L].a;
			L++;
		}else{
			L++,R--;
		}
	}cout<<ans;
}
/*####################*/
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T=1;//cin>>T;
	while(T--) Solve();
	return 0;
}
