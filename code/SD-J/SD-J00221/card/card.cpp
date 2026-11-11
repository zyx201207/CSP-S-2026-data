#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
stack<int>st;
int n,m;
bool f[N];
int cnt[N],a[N];
void baoli(){
	for(int s=1;s<=n;s++){
		for(int i=s;i<=n;i++){
			while(f[a[i]]){
				f[st.top()]=0;
				st.pop();
			}
			f[a[i]]=1;
			st.push(a[i]);
		}
//	for(int i=1;i<=m;i++) cout<<f[i]<<' ';
//	cout<<"\n";
		while(!st.empty()){
			cnt[st.top()]++;
			f[st.top()]=0;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	exit(0); 
}
void bufenA(){
	for(int i=1;i<=n;i++){
		cnt[a[i]]=max(cnt[a[i]],i);
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	exit(0); 
}
void bufenB(){
	int k=1;
	for(int s=1;s<=n;s++){
		if(a[s]!=a[s+1]){
			while(!st.empty()){
				cnt[st.top()]+=k;
				f[st.top()]=0;
				st.pop();
			}
			k=1;
			for(int i=s;i<=n;i++){
				while(f[a[i]]){
					f[st.top()]=0;
					st.pop();
				}
				f[a[i]]=1;
				st.push(a[i]);
			}
		}
		else k++;
//	for(int i=1;i<=m;i++) cout<<f[i]<<' ';
//	cout<<"\n";
	}
	cnt[a[n]]++;
	for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	exit(0); 
}
int cnt1[N];
int ans[N];
void get(){
	for(int i=1;i<=n;i++){
		cnt[a[i]]++;
	}
//	cnt[a[n]]=n;
	int sum=0;
	for(int i=1;i<=n;i++){
		if(f[a[i]]){
			sum--;
			continue;
		} 
		f[a[i]]=1;
		cnt1[a[i]]++;
		int k=cnt[a[i]]-cnt1[a[i]];
		sum+=k;
	//	sum+=cnt[a[i]];
		ans[a[i]]=k; 
		
	}
	for(int i=1;i<=m;i++){
	//	cnt[i]=
		cout<<ans[i]+cnt[i]<<' ';
	}
	exit(0);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool fl=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) fl=0;
	}
	if(n<=5000) bufenB();
	else get();
	for(int s=1;s<=n;s++){
		for(int i=s;i<=n;i++){
			while(f[a[i]]){
				f[st.top()]=0;
				st.pop();
			}
			f[a[i]]=1;
			st.push(a[i]);
		}
	for(int i=1;i<=m;i++) cout<<f[i]<<' ';
	cout<<"\n";
		while(!st.empty()){
			cnt[st.top()]++;
			f[st.top()]=0;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	return 0;
} 
/*

4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1

3 1 4









1 0 1
1 0 0
1 1 0
1 0 0
1 0 1
1 1 0
1 0 1
1 0 0
1 1 0
1 0 0



*/
