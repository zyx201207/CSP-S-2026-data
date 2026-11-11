#include<bits/stdc++.h>
using namespace std;
int n,t,c,d,tot,head[2000005];
struct node{
	int num,w,next,to;
}a[2000005];
void add(int u,int v){
	tot++;
	a[tot].w = 1;
	a[tot].to = v;
	a[tot].next = head[u];
	head[u] = tot;

}
int main(){
	freopen("migrate4.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){

		cin >> n >> d;
		int sum  = 0;
		d = 2*d-1;
		int cnt = 1;
		for(int i = 1;i<=n;i++){
			cin >> a[i];
			if(a[i]-a[cnt]== d){
				sum++;
			}else if(a[i]>a[cnt]+d){
				while(a[i]+d>a[cnt]){
					cnt++;
				}
			}
		}
		cout << sum << endl;


}
}
