#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n;
long long m;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	if(n==1){
		cout << 1 << endl;
	}else{
	deque<int> que;
	sort(a+1,a+n+1);
	long long qst=0;
	int mal=0;
	for(int i=1;i<=n;i++){
		qst+=1ll*que.size()*(a[i]-a[i-1]);
		que.push_back(a[i]);
		while(qst>m&&!que.empty()){
			qst-=a[i]-que.front();
			que.pop_front();
		}
		if(mal<que.size()) mal=que.size();
	}
	cout << mal << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
