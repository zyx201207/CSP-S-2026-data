//姓名:张泽凯,考号:SN-S00484,学校:西安交通大学附属中学 
#include<bits/stdc++.h>
using namespace std;
long long n,m,mx=0,tmp=0;
bool xd=1;
struct s{
	int num;
	int z;
};
bool cmp1(s q,s w){
	return q.z<w.z;
}
bool cmp2(s q,s w){
	return q.num<w.num;
}
s a[500003]={};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i].z;
		a[i].num=i;
		if(i>=2){
			if(a[i].z!=a[i-1].z)xd=0;
		}
	}
	if(xd==1){
		cout<<n;
		return 0;
	}
	for(long long i=1;i<=m;i++){
		tmp=1;
		sort(a+1,a+n+1,cmp2);
		for(int i=2;i<=n;i++){
			if(a[i].z==a[i-1].z)++tmp;
			else{
				mx=max(mx,tmp);
				tmp=1;
			}
		}
		sort(a+1,a+n+1,cmp1);
		++a[1].z;
	}
	tmp=1;
	sort(a+1,a+n+1,cmp2);
	for(long long i=2;i<=n;i++){
		if(a[i].z==a[i-1].z)++tmp;
		else{
			mx=max(mx,tmp);
			tmp=1;
		}
	}
	cout<<mx;
	return 0;
}
