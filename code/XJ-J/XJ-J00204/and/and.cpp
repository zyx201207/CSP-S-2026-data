#include<bits/stdc++.h>
using namespace std;
int t[1000010];
struct number{
	int pos;
	int num;
}a[1000010];
int cmp1(number a,number b){
	if(a.num!=b.num){
		return t[a.pos]>t[b.pos];
	}
	else{
		return a.num>b.num;
	}
}
int cmp(number a,number b){
	return a.num>b.num;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	memset(t,0,sizeof(t));
	int m,n;
	cin>>n>>m;
	//cout<<"MNOK\n";
	for(int i=1;i<=n;i++){
		//int a;
		cin>>a[i].num;
		a[i].pos=i;
		int as=a[i].num;
		while(as!=0){
			int last=as&1;
			if(last)t[i]++;
			as>>=1;
		}
		//cout<<"i:"<<i<<"a"<<a[i].num<<endl;
	}
	//cout<<"ATOK\n";
	sort(a+1,a+n+1,cmp1);
	/*for(int i=1;i<=n;i++){
		cout<<a[i].num<<" ";
	}*/
	int ans1=a[1].num;
	int sm=m;
	//cout<<"======\n"<< (a[1]&a[2]) <<"======\n";
	int mn=m;
	for(int i=2;i<=m;i++){
		//cout<<"ans:"<<ans1<<"a[i]"<<a[i].num<<endl;
		if((ans1&a[i].num)==0&&i!=n-mn){
			m+=1;
			continue;
		}
		ans1&=a[i].num;
		mn--;
	}
	//cout<<ans1<<endl;
	sort(a+1,a+n+1,cmp);
	mn=sm;
	int ans2=a[1].num;
	//cout<<sm;
	for(int i=2;i<=sm;i++){
		//cout<<"ans:"<<ans2<<"a[i]"<<a[i].num<<endl<<mn<<" \n";
		if((ans2&a[i].num)==0&&i!=n-mn){
			sm+=1;
			continue;
		}
		ans2&=a[i].num;
		mn--;
	}
	cout<<max(ans1,ans2);
}
/*
4 2
3 15 12 12
*/
