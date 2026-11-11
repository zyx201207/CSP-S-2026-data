#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],ans[300010];
string s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		s="";
		for(int j=i;j<=n;j++){
			char ch=a[j]+'0';
			if(s.size()!=0&&s.find(ch)<=s.size()){
				s="";
			}
			s+=ch;
		}
		for(int k=1;k<=m;k++){
			if(s.size()!=0&&s.find(k+'0')<=s.size())ans[k]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" "; 
	}
	return 0;
}
