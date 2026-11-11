//最后一道题居然不是dp 难道只能TLE了吗 呃啊 还真是
#include<iostream>
#include<stack>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m;
int a[500005],t[500005],ans[500005];
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int o=1;o<=n;o++){
		memset(t,0,sizeof(t));
		for(int i=o;i<=n;i++){
			if(t[a[i]]){
				t[s.top()]=0;
				s.pop();
				while(!s.empty()&&s.top()!=a[i]){
					t[s.top()]=0;
					s.pop();
				}
//				s.pop();
			}else{
				s.push(a[i]);
				t[a[i]]=1;
			}
		}
		while(!s.empty()){
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}

