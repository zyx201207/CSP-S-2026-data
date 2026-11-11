#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,f1=1;
int a[N],ans[M];
stack<int> st;
stack<int> la[M]; 
void t1(){
	a[n+1]=-1;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i+1]) cout<<i<<' ';
	}
}
void t2(){
	int cnt=0;
	for(int i=1;i<=n;i++) if(a[i]==1) cnt++;
	if(a[n]==1) cout<<n<<' '<<n-cnt;
	else cout<<cnt<<' '<<n;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1&&a[i]<a[i-1]) f1=0;
	}
	if(f1){
		t1();
		return 0; 
	}
	if(m==2){
		t2();
		return 0;
	}
	for(int i=1;i<=n;i++){
		while(!st.empty()) st.pop();
		for(int j=1;j<=m;j++) while(!la[j].empty()) la[j].pop();
		for(int j=i;j<=n;j++){
			if(!la[a[j]].empty()){
				while(st.top()!=a[j]){
					la[st.top()].pop();
					st.pop();
				}
				la[a[j]].pop();
				st.pop();
			}
			st.push(a[j]);
			la[a[j]].push(j);
		}
		for(int j=1;j<=m;j++) if(!la[j].empty()) ans[j]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
