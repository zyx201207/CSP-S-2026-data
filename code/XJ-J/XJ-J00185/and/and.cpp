#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
const int N=2e5+5;
int n,m,a[N];
string s[N];
int cnt,ans;
queue<int> q;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q.push(i);
		int t=a[i];
		while(t!=0){
			s[i]=char(t%2+'0')+s[i];
			t/=2;
		}
		while(s[i].size()<30) s[i]='0'+s[i];
	}
	for(int j=0;j<30;j++){
		cnt=0;
		for(int i=0;i<q.size();i++){
			if(s[q.front()][j]=='1') cnt++;
			q.push(q.front());
			q.pop();
		}
		
		if(cnt<m) continue;
		ans|=(1<<(29-j));
		int k=q.size();
		for(int i=0;i<k;i++){
			int now=q.front();
			if(s[now][j]!='1') q.pop();
		}
	}
	cout<<ans;
	return 0;
}
