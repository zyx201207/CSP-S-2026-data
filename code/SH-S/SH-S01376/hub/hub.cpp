#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
signed main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	int n,m;
	int x;
	deque<int> q;
	queue<int> q2;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		while(!q.empty()&&q.back()>x)q.pop_back();
		while(!q.empty()&&m-abs(x-q.back())<0&&!q2.empty()){
			q.pop_front();
			m+=q2.front();
			q2.pop();
		}
		if(!q.empty()){
			m-=abs(x-q.back());
			q2.push(abs(x-q.back()));
		}
		else{
			q2.push(0);
		}
		q.push_back(x);
	}
	cout<<q.size();
	return 0;
} 
//图灵老师保佑
//冯诺依曼老师保佑
//高斯老师保佑
//祖冲之老师保佑 
//今天是阳明老师的生辰诶…………554岁生辰快乐awa 
//以及今天是万圣节……万圣节给圣贤过生辰，这很合理awa
//0v0
//freopen
//嗯对的cos一下张仪
//我是cutecat1
 
