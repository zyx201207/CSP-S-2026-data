#include<bits/stdc++.h>
using namespace std;
int n;
long long m,d;
vector<long long> num;
vector<long long> qzh;
queue<long long> cnt;
map<long long,int> pre;
int qzqiuhe(int start,int last){
	int num1;
	for (int i=start;i<=last;i++){
		num1+=qzh[i];
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>d;
		num.push_back(d);
	}
	sort(num.begin(),num.end());
	pre[num[0]]=0;
	for (int i=1;i<n;i++){
		pre[num[i]]=i;
		qzh.push_back(num[i]-num[i-1]);
	}
	long long power=0;
	cnt.push(num[0]);
	int ans=0;
	for (int i=1;i<n;i++){
		cnt.push(num[i]);
		power+=((cnt.size()-1)*qzh[i-1]);
		long long qz1=qzqiuhe(pre[cnt.front()]-1,pre[num[i]]-1);
		while(power>m){
			cnt.pop();
			power-=qz1;
			qz1-=qzh[pre[cnt.front()]-1];
		}
		int f=cnt.size();
		ans=max(ans,f);
	}
	cout<<ans;
	return 0;
}
