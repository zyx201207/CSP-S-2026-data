#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
bool Aflag;
int n,m;
int a[maxn];
int f[maxn];
int ans[maxn];

void subA(){
	
	for(int i=1;i<=n;i++){
		ans[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return ;
	
}

void nn(){
	for(int tt=1;tt<=n;tt++){
		stack<int> st;
		memset(f,0,sizeof f);
		for(int i=tt;i<=n;i++){
			if(!f[a[i]]){
				st.push(a[i]);
				f[a[i]]++;
			}else{
				while(st.top()!=a[i]){
					f[st.top()]--;
					st.pop();
				}
			}
		}
		while(!st.empty()){
			ans[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}

void meq2(){
	int sum1=0,sum2=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1) sum1++;
		else sum2++;
	}
	if(a[n]==1) cout<<n<<" "<<sum2;
	else cout<<sum1<<" "<<n;
}

signed main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			Aflag=1;
		}
	}
	if(Aflag==0){
		subA();
	}else if(n<=5000){
		nn();
	}else if(m==2){
		meq2();
	}else{
		//f**k **F
	}
	return 0;
}
/**
wo jiu shuo (luogu uid=1129853) shi qv ba.
bai lei yong yuan shi bai lei
bai lei yong yuan shi bai lei
bai lei yong yuan shi bai lei
bai lei yong yuan shi bai lei
bai lei yong yuan shi bai lei
bai lei yong yuan shi bai lei
bai lei yong yuan shi bai lei
bai lei yong yuan shi bai lei
**/
