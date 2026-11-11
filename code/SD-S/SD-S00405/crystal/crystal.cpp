#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long T = 1e9;
unsigned long long m,t;
int n;
struct node{
	bool ab;
	long long a;
}g[N];
//0 ÎªÕı 
void read(int p){
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c == '-')g[p].ab++;
		c = getchar(); 
	}
	while(c>='0'&&c<='9'){
		g[p].a*=10;
		g[p].a+=(c-'0');
		c = getchar(); 
	}
	return;
}
//__int128 rd(){
//	__int128 x=0,y=1;
//	char c;
//	while(c=getchar()){
//		if(c == '-')y*=-1;
//	}
//	while(c=getchar()&&c>='0'&&c<='9'){
//		x*=10;
//		x+=(c-'0'); 
//	}
//	return x*y;
//}
bool cmp(node u,node v){
	if(u.ab != v.ab)return u.ab > v.ab;
	else if(u.ab == 0&&v.ab == 0)return u.a < v.a;
	else return u.a > v.a;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	if(n==1){
		cout << "1\n";
		return 0;
	}
	if(m > T){
		//cout << m<< "****\n";
		long long a_1,a_2,a_;
		cin >> a_1 >> a_2;a_=abs(a_1-a_2);
		//cout << a_;
		for(int i = 1;i <= n;i ++){
			if(m < i*a_){
				cout << i;
				return 0;
			}
			m = m-i*a_;
		}
		cout << n;
		return 0;
	}else{
	for(int i = 1;i <= n;i ++){
		cin >> g[i].a;
		if(g[i].a<0)g[i].ab=1,g[i].a*=-1;
	}
	sort(g+1,g+1+n,cmp);
//	for(int i = 1;i <= n;i ++){
//		if(g[i].ab)cout << "-";
//		cout << g[i].a << " ";
//	}
	int j,ans = 0,cnt = 0; 
	for(int i = 1;i < n;i ++){
		j = i+1;
		t = m;
		cnt = 1;
		int p = i;
		while(j <= n){
			bool f=0;
			if(g[p].ab == g[j].ab){
				if(g[p].ab){
					if(t >= (g[p].a-g[j].a)*cnt){
						t -= (g[p].a-g[j].a)*cnt;
						cnt ++;
						j ++;
						p ++;
						f = 1;
						//cout << t<< "***\n";
					}
				}else{
					if(t >= (g[j].a-g[p].a)*cnt){
						t -= (g[j].a-g[p].a)*cnt;
						j ++;
						p ++;
						cnt ++;
						f = 1;
						//cout << t<< "***\n";
					}
				}
			}
			else{
				if(t >= (g[p].a+g[j].a)*cnt){
					t -= (g[p].a+g[j].a)*cnt;
					j ++;
					cnt ++;
					p ++;
					f = 1;
					//cout << t<< "***\n";
				}
			}
			if(!f)break;
    	}
    	///cout << "\n";
		if(cnt > ans)ans = cnt;
	}
	cout << ans;
}
	return 0;
}
