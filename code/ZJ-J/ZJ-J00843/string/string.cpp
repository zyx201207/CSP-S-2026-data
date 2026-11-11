#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
struct node{
	int gs;
	char zl;	
};
node a[N];
queue<node> q;
int n,zgs;
int xb;
int ans;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++){
		int x;char y;
		cin >> x >> y;
		q.push({x,y});
		zgs+=x;
	}
	int dq = 0,syg = 0;;
	int zygs = zgs/2;
	bool o = 0;
	if(zgs%2==0) o = 1;
	else o = 0;
	bool tc = 0;
	while(1){
		syg = dq;
		dq += q.front().gs;
		if(dq<=zygs){
			a[++xb].gs = q.front().gs;
			a[xb].zl = q.front().zl;
			q.pop();
			if(dq==zygs){
				tc=1;
				break;
			}
		}else{
			if(o==0){
				a[++xb].gs = zygs-syg+1;
				a[xb].zl = q.front().zl;
				int fjx = xb;
				a[++xb].gs = q.front().gs-(zygs-syg+1);
				a[xb].zl = q.front().zl;
				q.pop();
				break;
			}else{
				a[++xb].gs = zygs-syg;
				a[xb].zl = q.front().zl;
				int fjx = xb;
				a[++xb].gs = q.front().gs-(zygs-syg);
				a[xb].zl = q.front().zl;
				q.pop();
				break;
			}
		}          
	}
	if(tc==1&&o==0) q.front().gs--;
	while(!q.empty()){
		a[++xb].gs = q.front().gs;
		a[xb].zl = q.front().zl;
		q.pop();
	}
//	for(int i = 1;i<=xb;i++){
//		cout << a[i].gs << " " << a[i].zl << "\n";
//	}
	int l = 1,lzl = a[1].zl,r = n,rzl = a[n].zl;
	int lzgs = a[1].gs;
	int yzgs = a[n].gs;
	while(l<r&&lzgs<=zygs&&yzgs<=zygs){
		lzl = a[l].zl,rzl = a[r].zl;
		if(lzl==rzl){
			if(a[l].gs==a[r].gs){
				l++;
				r--;
				lzgs+=a[l].gs;
				yzgs+=a[r].gs;
			}else if(a[l].gs>a[r].gs){;
				r--;
				a[l].gs-=a[r].gs;
				yzgs+=a[r].gs;
			}else if(a[l].gs<a[r].gs){
				l++;
				a[r].gs-=a[l].gs;
				lzgs+=a[l].gs;
			}
		}else{
			if(a[l].gs==a[r].gs){
				ans+=a[l].gs;
				l++;
				r--;
				lzgs+=a[l].gs;
				yzgs+=a[r].gs;
			}else if(a[l].gs>a[r].gs){
				ans+=a[l].gs-a[r].gs;
				r--;
				a[l].gs-=a[r].gs;
				yzgs+=a[r].gs;
			}else if(a[l].gs<a[r].gs){
				ans+=a[r].gs-a[l].gs;
				l++;
				a[r].gs-=a[l].gs;
				lzgs+=a[l].gs;
			}
		}
	}
	cout << ans;
	return 0;
}