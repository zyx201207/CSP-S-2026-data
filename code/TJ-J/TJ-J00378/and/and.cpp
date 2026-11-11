#include<bits/stdc++.h>
using namespace std;
struct node{
	long long num;
	int  log;
};
node a[200005]={};
int result(int x,int y){
	long long sum=0,c=1;
	while(x!=0&&y!=0){
	    if(x%2==y%2&&x%2==1){
		    sum+=c;
	    }
	    x/=2;
	    y/=2;
	    c*=2;
	}
	return sum;
}
bool cmp(node x,node y){
	if(x.num!=y.num){
		return x.log>y.log;
	}
	return x.num>y.num;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].num;
	}
    for(int i=1;i<=n;i++){
    	long long temp=a[i].num;
    	while(temp!=0){
    		temp/=2;
    		a[i].log++;
		}
	}
	sort(a+1,a+1+n,cmp);
	int cnt=0;
	bool flag=1;
	for(int i=1;i<=m;i++){
		if(flag){
			cnt=result(a[i].num,a[i+1].num);
			flag=0;
		}
		else{
			cnt=result(cnt,a[i].num);
		}  
	}
	cout<<cnt;
	return 0;
}
