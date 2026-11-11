#include<bits/stdc++.h>
#define ll long long
#define mes(a,b) memset(a,b,sizeof a);
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f 
using namespace std;
const int N=2e5+10;
struct node{
	int t;
	int cnt_end,cnt_front;
}a[N];
int n,m;
int f[40];
int ans;
int max_bit=-inf;
void poos(int i){
	int t=a[i].t;
	while(t%2==0){
		a[i].cnt_end++;
		t/=2;
	}
	t=a[i].t;
	int cnt=0;
	while(t>=f[cnt]) cnt++;
	int bt=0;
	if(t<=15){
		bt=4;
	}else if(t<=255){
		bt=8;
	}else if(t<=4095){
		bt=12;
	}else if(t<=65535){
		bt=16;
	}else if(t<=1048575){
		bt=20;
	}else if(t<=16777215){
		bt=24;
	}else if(t<=268435455){
		bt=28;
	}else if(t<=1073741823){
		bt=30;
	}
	max_bit=max(bt,max_bit);
	a[i].cnt_front=max_bit-cnt;
}
bool cmp(node x,node y){
	if(x.cnt_front==y.cnt_front) return x.cnt_end<y.cnt_end;
	return x.cnt_front<y.cnt_front; 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<=30;i++){
		f[i]=pow(2,i);
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].t;
		poos(i);
	}
	sort(a+1,a+1+n,cmp);
	ans=a[1].t;
	for(int i=2;i<=m;i++){
		ans&=a[i].t;
	}
	cout<<ans;
	return 0;
}
