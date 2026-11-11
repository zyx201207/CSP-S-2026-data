#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

struct node{
	int a;
	char b;
} c;
vector<node> z;
queue<node> m;
int n,x,cnt=0,ans = 0,cc=-1,l,r,minn;
bool ccnt;
char y;
string a;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> x >> y;
		//cout <<x<< " "<<y<<endl;
		cnt += x;
		m.push({x,y});
	}
	if(cnt % 2 == 1) ccnt=1;
	cnt = (cnt+1)/2;
	for(int i = 1;i<=n;i++){
		if(m.front().a < cnt){
			z.push_back(m.front());
			cc++;
			cnt -= m.front().a;
		}
		else{
			if(cnt){
				m.front().a -= cnt;
				z.push_back({cnt-ccnt,m.front().b});
				cc++;
				cnt = 0;
			}
			while(m.front().a){
				//cout << cc << " ";
				minn = min(m.front().a,z[cc].a);
				if(m.front().b != z[cc].b){
					//cout << m.front().b << " " << z[cc].b<<endl;
					ans += minn;
				}
				m.front().a -= minn;
				if(z[cc].a == minn) cc--;
				else z[cc].a -= minn;
			}
		}
		m.pop();
	}
	cout << ans;
	return 0;
}
