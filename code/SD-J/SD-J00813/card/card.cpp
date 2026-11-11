#include<bits/stdc++.h>
using namespace std;
const int N=5E5+5;
unordered_map<int,int> mp;
int ans[N];
int pt[N];
int kind[N];
int num=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>pt[i];
		bool flag=true;
		for (int j=1;j<i;j++){
			if (pt[j]==pt[i]){
				flag=false;
				break;
			}
		}
		if(flag) kind[++num]=pt[i];
	}
	sort(kind+1,kind+m+1);
	stack<int> s;
	for (int i=1;i<=n;i++){
		while (!s.empty()){
			s.pop();
		}
		for (int j=1;j<=n;j++){
			if (mp[pt[j]]) mp[pt[j]]=0;
		}
		for (int j=i;j<=n;j++){
			if (mp[pt[j]]){
				while (!s.empty()){
					if (s.top()==pt[j]){
						s.pop();
						mp[pt[j]]=0;
						break;
					}
					mp[s.top()]=0;
					s.pop();
				}
			}
			mp[pt[j]]=1;
			s.push(pt[j]);
		}
		for (int i=1;i<=m;i++){
			if (mp[kind[i]]){
				ans[i]++;
			}
		}
	}
	for (int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
