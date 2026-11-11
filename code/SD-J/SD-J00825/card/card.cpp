#include<bits/stdc++.h>
using namespace std;
const int N=5e5+9;
const int M=3e5+9;
int a[N],t[M];
int ans[M],n,m;
stack<int> s;
int cnt=1;
bool check(int a){
	bool pd=0;
	while(s.size()){
		int x=s.top();
		s.pop();
		cnt++;
		if(x==a){
			pd=1;
			break;
		}
	}
	if(pd==1){
		return 1;
	}
	else{
		cnt=1;
		return 0;
	}
}
void superpop(int cnt){
	while(cnt>0){
		s.pop();
		cnt--;
	}
	return ;
}


int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			check(a[j]);
			if(check(a[j])==1){
				superpop(cnt);
				cnt=1;
				s.push(a[j]);
			}
			else{
				s.push(a[j]);
			}
		}
		while(s.size()){
			int x=s.top();
			s.pop();
			ans[x]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
