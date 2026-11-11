#include<bits/stdc++.h>
using namespace std;
struct node{
	int step,pos;	
};
const int N = 2e6+5;
int c,t,ans,a[N],n,stp[N],ans_stp[N];
long long d;

void bfs(int x){
	memset(stp,0x3f,sizeof(stp));
	memset(ans_stp,0x3f,sizeof(ans_stp));
	int min_step = INT_MAX;
	queue<node> q;
	q.push({0,x});
	while(!q.empty()){
		node head = q.front();
		q.pop();
		if(head.pos == n)
			continue;
		for(int i = head.pos+1;a[head.pos]*1LL+d>=a[i]*1LL && i<=n;i++){
			if(head.step+1==stp[i] && ans_stp[i]<=3){
				ans_stp[i]++;
				q.push({head.step+1,i});
			}else if(head.step+1<=stp[i] && ans_stp[i]<=3){
				ans_stp[i] = 1;
				stp[i] = head.step+1;
				q.push({head.step+1,i});
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> t;
	while(t--){
		ans = 0;
		memset(a,0,sizeof(a));
		
		cin >> n >> d;
		for(int i = 1;i<=n;i++)	cin >> a[i];
		if(0<=c<=10){
			for(int i = 1;i<n;i++){
				bfs(i);
				for(int j = i;j<=n;j++)
					if(ans_stp[j] == 2)	ans++;
			}
			cout << ans << '\n';
		}else if(c == 11 || c == 12){
			bfs(1);
			for(int i = 1;i<=n;i++)
				if(ans_stp[i] == 2)	ans+=(n-i+1);
			cout << ans << '\n';	
		}else if(c == 13|| c == 14){
			int spe;
			for(int i = 1;i<=n;i++){
				if(a[i]-a[1]<=d && a[n]-a[i]<=d){
					spe = i;
					break;
				}	
			}
			int s = a[spe-1]+d;
			int pos = lower_bound(a+spe+1,a+n+1,s)-a;
			ans = (n-pos+1);
			cout << ans << '\n';
		}
	}
	return 0;
}
