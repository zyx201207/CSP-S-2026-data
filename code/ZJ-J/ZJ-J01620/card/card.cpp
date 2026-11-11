#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],t[500005],st[500005];
stack<int> s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			while(st[a[j]]!=0){
				st[s.top()]--;
				s.pop();
			}
			s.push(a[j]);
			st[a[j]]++;
		}
		while(!s.empty()){
			t[s.top()]++;
			st[s.top()]--;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}
