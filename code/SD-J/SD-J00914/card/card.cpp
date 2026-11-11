#include<bits/stdc++.h>
using namespace std;
int n,m,a[500003],f,l[500003],cnt[300003];
bool inn[300003];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>a[i])f=1;
		l[a[i]]=i;
	}if(f==0)for(int i=1;i<=m;++i)cout<<l[i]<<' ';
	else{
		for(int i=1;i<=n;i++){
			stack<int>s;
			for(int j=i;j<=n;j++){
				if(inn[a[j]]){
					while(s.top()!=a[j]){
						inn[s.top()]=0;
						s.pop();
					}
				}else{
					inn[a[j]]=1;
					s.push(a[j]);
				}
			}while(s.size()){
				cnt[s.top()]++;
				inn[s.top()]=0;
				s.pop();
			}
		}for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
	}return 0;
}
