#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define to0(x) memset(x,0,sizeof x)
#define to_1(x) memset(x,-1,sizeof x)
#define toinf(x) memset(x,0x3f,sizeof x)
#define Debug cout<<"DEBUG\n";
#define Deon(x) cout<<"DEBUG:"<<x<<'\n';
#define pb(x) push_back(x)
#define CLOSE ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

const int N = 2e5+5;
struct Node {
	int le,id;
	char c;
}a[N];
int n;
ll L,as=0; 

int main() {
  freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i].le>>a[i].c;
		a[i].id=i; 
		L+=a[i].le;
	}
	ll j=n,i=1,j_pos=L,i_pos=1,j_bnd=L-a[j].le+1,i_bnd=0+a[i].le;
	while(1) {
		int ile=i_bnd-i_pos+1,jle=j_pos-j_bnd+1;
//		cout<<i<<" "<<i_pos<<" "<<i_bnd<<'\n';
//		cout<<j<<" "<<j_pos<<" "<<j_bnd<<'\n'<<'\n';
		if(i_bnd-i_pos+1<j_pos-j_bnd+1&&i+1<=j) {
			if(a[i].c!=a[j].c) {
				as+=(i_bnd-i_pos+1);
			}
			j_pos-=ile,i_pos+=ile;
			i++;i_bnd=i_pos+a[i].le-1;
		}
		else if(i_bnd-i_pos+1>j_pos-j_bnd+1&&i<=j-1) {
			if(a[i].c!=a[j].c) {				
				as+=(j_pos-j_bnd+1);
			}
			j_pos-=jle,i_pos+=jle;
			j--;j_bnd=j_pos-a[j].le+1;
		} 
		else if(i_bnd-i_pos+1==j_pos-j_bnd+1&&i+1<=j-1) {
			if(a[i].c!=a[j].c) {
				as+=(j_pos-j_bnd+1);
			}
			j_pos-=ile,i_pos+=ile;
			i++;i_bnd=i_pos+a[i].le-1;
			j--;j_bnd=j_pos-a[j].le+1;
		}
		if(i==j||i_pos>L/2||j_pos<L/2) break;
	}
	cout<<as;

	return 0;
}
/*
考虑到一个回文串必定是对称的
所以修改数<=>对应位置不同的位置数
首先找到回文中心，然后双指针的跳，每次直接跳块长
as+=max-min
j+=max,i-=max
O(N)，L和as开long long  
或者向中心跳更好写
 
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

4
2 a 
3 c
1 a
1 c
*/ 
