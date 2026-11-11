#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
long long a[N];
long long ans[M];
long long t[N];
long long n,m;
bool p=1;

void tp(){
	for(int i=1;i<=n;i++){
		t[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		t[i]=t[i]+t[i-1];
		cout<<t[i]<<' ';
	}
	cout<<'\n';
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1&&a[i]<a[i-1]){
			p=0;
		}
	}
	if(p){
		tp();
		return 0;
	}
	for(int i=1;i<=n;i++){
		stack<long long >s;
		for(int j=i;j<=n;j++){
			if(t[a[j]]){
				while(s.top()!=a[j]){
					t[s.top()]=0;
					s.pop();
				}
			}else{
				s.push(a[j]);
				t[a[j]]=1;
			}
		}
		while(!s.empty()){
			long long x=s.top();
			t[x]=0;
			ans[x]++;
			s.pop();
		}
		//cout<<1;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
