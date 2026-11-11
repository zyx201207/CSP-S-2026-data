#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long long n,m,b[200005],sum;
struct node{
	int x;
	int y;
}a[200005];
int cmp(node q,node w){
	if(q.y==w.y) return q.x>w.x;
	return q.y>w.y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//cout<<log2(33);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;

	}
	for(int i=1;i<=n;i++){
		int x=log2(a[i].x)+1;
		long long w=pow(2,x);
		int u=a[i].x,z=x,cnt=0;
		while(u!=0){
			if(u>=pow(2,z)){
				u-=pow(2,z);
				cnt++;
			}
			z--;
		}
		a[i].y=cnt;
			
	}
	sort(a+1,a+n+1,cmp);
	
	sum=a[1].x;
	for(int i=2;i<=m;i++) {
		sum=(sum&a[i].x);
	}
	cout<<sum;
	return 0;
} /*
1144

 16 8 4 2 1
z=0
u=1

111111111
111111110
111111110
111111101
111111100

12

1100
0100
10000
10010
11000
10001
00110


3

100000
010000
000001


00011



11011

*/  
