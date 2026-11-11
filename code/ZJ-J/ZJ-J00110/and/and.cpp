#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//head

struct node{
	int val;
	char wei[31];
};
//class

int n,m,ans,nw;
node a[200010];
//val

bool cmp(node a,node b){
	return a.val>b.val;
}
bool cmp2(node a,node b){
	return a.wei[nw]>b.wei[nw];
}
void func(int w,int l,int r,int num){
	if(w<0) return;
	nw=w;
	sort(a+l,a+r+1,cmp2);
	int pos=r;
	for(int i=l;i<=r;i++){
		if(a[i].wei[w]=='0'){
			pos=i;
			break;
		}
	}
	int sum=pos-l;
	//cout<<pos<<' '<<sum<<' '<<num<<' ';
	if(sum>=num){
		//cout<<1<<'\n';
		ans+=(1<<w);
		func(w-1,l,pos-1,num);
	}else{
		//cout<<0<<'\n';
		func(w-1,l,r,num);
	}
}
//func

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].val;
		int tmp=a[i].val;
		for(int j=29;j>=0;j--){
			if(tmp>=(1<<j)){
				a[i].wei[j]='1';
				tmp-=(1<<j);
			}else{
				a[i].wei[j]='0';
			}
		}
		//cout<<a[i].wei<<'\n';
	}
	sort(a+1,a+1+n,cmp);
	/*
	for(int i=1;i<=10;i++){
		cout<<a[i].wei<<' ';
	}
	cout<<'\n';
	*/
	func(29,1,n,m);
	cout<<ans;
	
	return 0;
}
