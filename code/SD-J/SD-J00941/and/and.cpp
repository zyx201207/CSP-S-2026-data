#include<iostream> 
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
int ans=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	ans=a[1];
	int pos=2;
	for(int i=1;i<=m;i++){
		ans+=pos;
	} 
	cout<<pos;
	cout<<12;
	return 0;
}
