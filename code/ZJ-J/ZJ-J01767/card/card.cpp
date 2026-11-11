#include<bits/stdc++.h>
using namespace std;
#define For(i ,x ,y) for(int i = x; i <= y; ++ i)
#define Down(i ,x ,y) for(int i = x; i >= y; -- i)
#define int long long
queue<int> q1;
queue<int> q2;
queue<int> q3;
queue<int> q4;
queue<int> p;
queue<int> p1;
bool pp;
int n ,m ,x ,a[310000] ,t ,l ,b[310000];
signed main(){
	freopen("card.in" ,"r" ,stdin);
	freopen("card.out" ,"w" ,stdout);
	cin >> n >> m;
	For(i ,1 ,n) cin >> x,p.push(x);
	p1 = p;
	For(i ,1 ,n){
		q1 = p;
		q2 = p;			
		while(!q2.empty()){
			t = q2.front();
			q2.pop();
			while(!q1.empty()){
				l = q1.front();
				if(l == t) break;
				q3.push(l);
				q1.pop();
			}
			q3.push(t);
			q1 = q3;
			q3 = q4;
		}
		while(!q1.empty()) {
			a[q1.front()] ++;
			q1.pop();
		}
		p.pop();
	}
	For(i ,1 ,m) cout << a[i] << ' ';
	return 0;
}