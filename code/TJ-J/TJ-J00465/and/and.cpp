#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int n,m,a[N],c[N],ans,tong[32];
vector<int>b[N];
stack<int>st;
bool cmp(vector<int>x,vector<int>y){
//	for(auto t:x)cout<<t;
//	cout<<" ";
//	for(auto t:y)cout<<t;
//	cout<<":::";
	for(int i=0;i<=30;i++){
		if(tong[i]<m)continue;
//		cout<<tong[i]<<"|";
		if(x[i]!=y[i]){
//			cout<<" "<<x[i]<<"::"<<y[i]<<" ";
//			cout<<"["<<i<<"]";
//			cout<<"\n";
			return x[i]>y[i];
		}
	}
//	cout<<"\n";
	return true;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
//		cout<<i<<" ";
		cin>>a[i];
//		if(i==199934)cout<<"\n"<<a[i];
		int x=a[i],cnt=0;
		while(cnt<30){
			st.push(x%2);
			x/=2;
			cnt++;
		}
		while(!st.empty()){
			b[i].push_back(st.top());
			st.pop();
		}
		for(int j=0;j<30;j++)tong[j]+=b[i][j]/*,cout<<b[i][j]*/;
//		cout<<"\n";
	}
//	cout<<"\n";
//	for(int i=0;i<=30;i++)cout<<i<<":"<<tong[i]<<"\n";
//	cout<<"\n";
	sort(b+1,b+n+1,cmp);
//	cout<<"\n";
//	for(int i=1;i<=n;i++){
//		for(auto t:b[i])cout<<t;
//		cout<<"\n";
//	}
	for(int i=1;i<=n;i++)for(int j=0;j<30;j++)c[i]=c[i]*2+b[i][j];
	ans=c[1];
	for(int i=1;i<=m;i++)ans&=c[i];
	cout<<ans;
	return 0;
}
//1073741823
