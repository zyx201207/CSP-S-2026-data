#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
long long cnt[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
	stack<int>s;
	s.push(a[i]);
		for(int j=i+1;j<=n+1;j++){
			if(a[i]==a[j]&&!s.empty()){
				for(int k=1;k<=j-i;k++){
					s.pop();
				}
			}
			s.push(a[j]);
		}
		while(!s.empty()){
			for(int k=1;k<=n;k++){
				if(k==s.top()){
					cnt[k]++;
				}
			}
			//cout<<s.top()<<" ";
			s.pop();
		}
		//cout<<endl;
	}
	
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
