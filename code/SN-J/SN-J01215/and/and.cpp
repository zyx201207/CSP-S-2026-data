#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
int n,m;//z[]={1,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767,65535,131071,262143,524287,1048575};
//int la=1<<21-1;//20个1 
struct pos{
	int n,m;//a[i],,,1的个数 
}a[N];
bool cmp(pos a,pos b){
	if(a.m==b.m) return a.n>b.n;
	return a.m>b.m;
}
bool cmpz(pos a,pos b){
	return a.n>b.n;
}
int ds(int a){
	return a&(-a);
}
int main()
{
	//ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i].n;
	for(int i=1;i<=n;i++)
	{
		int x=a[i].n,cnt=0;
		while(x!=0){
			x-=ds(x);
			cnt++;
		}
		a[i].m=cnt;
//		cout<<a[i].n<<" "<<a[i].m<<endl;
	}
	sort(a+1,a+1+n,cmp);
	long long ans=a[1].n;
//	cout<<a[1].n;
	for(int i=2;i<=m;i++){
		ans&=a[i].n;
//		cout<<" "<<a[i].n;
	} 
	sort(a+1,a+1+n,cmpz);
	long long ans2=a[1].n;
	for(int i=2;i<=m;i++) ans2&=a[i].n;
	
	cout<<max(ans,ans2);
	return 0;
}
/*5 3
31 3 1 15 7
4 2
3 15 12 12

*/
