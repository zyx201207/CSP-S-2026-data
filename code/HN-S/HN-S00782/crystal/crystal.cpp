#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
stack<int>st;
int a[N];
long long n,m,m1,ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	m1=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(long long i=m;i>=1;i--){
		st.push(a[i]);
	}for(long long i=1;i<m1;i++){
		int x,y;
		x=st.top();
		st.pop();
		y=st.top();
		st.pop();
		if(abs(x-y)<=m){
			m-=abs(x-y);
			st.push(y);
			x+=abs(x-y);
			st.push(x);ans++;
			cout<<m<<" "<<x<<" "<<y<<endl;
		}if(x==y){
			st.pop();
			st.pop();
			st.push(x+y);
		}
		if(abs(x-y)>m){
			break;
		}
	}cout<<ans;
}
